class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // 1. Insert copied nodes
        Node* temp = head;
        while (temp) {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }

        // 2. Set random pointers
        temp = head;
        while (temp) {
            Node* copied = temp->next;
            copied->random = temp->random ? temp->random->next : nullptr;
            temp = copied->next;
        }

        // 3. Separate two lists
        Node* original = head;
        Node* copy = head->next;
        Node* copyHead = copy;

        while (original) {
            original->next = original->next->next;
            copy->next = (copy->next) ? copy->next->next : nullptr;

            original = original->next;
            copy = copy->next;
        }

        return copyHead;
    }
};
