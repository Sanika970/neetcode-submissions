class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int count = 0;
        ListNode* prev = head;

        while (prev != nullptr) {
            count++;
            prev = prev->next;
        }

        // Remove head
        if (count == n) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        prev = head;

        // Move to node before the one to delete
        for (int i = 1; i < count - n; i++) {
            prev = prev->next;
        }

        ListNode* temp = prev->next;
        prev->next = temp->next;
        delete temp;

        return head;
    }
};