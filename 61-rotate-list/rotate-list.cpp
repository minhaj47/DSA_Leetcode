class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Handle edge cases
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        // Find the length of the list and the tail node
        int length = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }

        // Normalize k
        k %= length;
        if (k == 0) {
            return head;
        }

        // Make the list circular
        tail->next = head;

        // Find the new tail: (length - k - 1) steps from head
        int stepsToNewTail = length - k - 1;
        ListNode* newTail = head;
        while (stepsToNewTail--) {
            newTail = newTail->next;
        }

        // Set the new head and break the circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};