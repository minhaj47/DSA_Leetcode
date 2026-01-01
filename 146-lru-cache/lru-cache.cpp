class Node {
public: 
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    unordered_map<int, Node*> cache;
    int cap;
    Node* head;
    Node* tail;

private: 
    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    void addNextToHead(Node* node) {
        Node* firstNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = firstNode;
        firstNode->prev = node;
    }
public:
    LRUCache(int capacity) {
        tail = new Node(0, 0);
        head = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }

    int get(int key) {
        if(cache.find(key) == cache.end()) {
            return -1;
        }
        Node* node = cache[key];
        remove(node);
        addNextToHead(node);
        return node->val;
    }

    void put(int key, int value) {
        // if already exists
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->val = value; // just change the value and move next to head;
            remove(node);
            addNextToHead(node);
            return;
        }

        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        addNextToHead(newNode);

        if(cache.size() > cap) {
            Node* lru = tail->prev;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }

    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */