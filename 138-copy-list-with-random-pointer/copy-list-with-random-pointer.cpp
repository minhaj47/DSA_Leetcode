/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        Node* dummy = new Node(0);
        Node* currCopied = dummy;

        unordered_map<Node*, Node*>mp;

        while(temp) {
            Node* newNode = new Node(temp->val);
            mp[temp] = newNode;
            currCopied->next = newNode;

            temp = temp->next;
            currCopied = currCopied->next;
        }

        temp = head;
        while(temp) {
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }
        return mp[head];
    }
};