/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* dummy = new ListNode();
        dummy->next = head; 
        ListNode* start = dummy;

        for(int i=1; i<left; i++) {
            start = start->next;
        }
        // start is at the last element of head

        ListNode* curr = start->next;
        ListNode* prev = nullptr;
        ListNode* tail = curr; // tail is the first element of rev seq

        for(int i=left; i<=right; i++) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        start->next = prev;
        tail->next = curr;

        return dummy->next;
    }
};