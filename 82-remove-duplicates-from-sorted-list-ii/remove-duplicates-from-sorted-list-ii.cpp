class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr) {

            if(curr->next && curr->val == curr->next->val) {
                while(curr->next && curr->val == curr->next->val) {
                    curr = curr->next;
                }
                // this just add in suspected list not final only changing the prev to prev->next finalize
                prev->next = curr->next; 
            } else {
                // this is the only valid number 
                // hence it will only add the number to the resultent ans
                prev = curr;
            }

            curr = curr->next;
        }
        return dummy->next;
    }
};
