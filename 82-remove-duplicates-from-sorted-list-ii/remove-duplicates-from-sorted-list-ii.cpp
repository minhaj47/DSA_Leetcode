class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* slow = &dummy;
        ListNode* fast = head;

        while (fast != nullptr) {
            // duplicates detected
            if (fast->next && fast->val == fast->next->val) {
                int val = fast->val;
                while (fast && fast->val == val) {
                    fast = fast->next;
                }
                slow->next = fast;
            } 
            // unique node
            else {
                slow = fast;
                fast = fast->next;
            }
        }
        return dummy.next;
    }
};
