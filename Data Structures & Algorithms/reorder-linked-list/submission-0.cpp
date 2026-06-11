class Solution {
public:
    void reorderList(ListNode* head) {

        if (head == nullptr) return;

        queue<int> q;
        stack<int> s;

        ListNode* temp = head;
        int n = 0;

        // Count nodes
        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }

        // Reset temp
        temp = head;

        // Fill queue
        for (int i = 0; i < n / 2; i++) {
            q.push(temp->val);
            temp = temp->next;
        }

        // Fill stack
        for (int i = n / 2; i < n; i++) {
            s.push(temp->val);
            temp = temp->next;
        }

        // Rewrite values in original list
        temp = head;

        while (!q.empty() || !s.empty()) {

            if (!q.empty()) {
                temp->val = q.front();
                q.pop();
                temp = temp->next;
            }

            if (!s.empty() && temp != nullptr) {
                temp->val = s.top();
                s.pop();
                temp = temp->next;
            }
        }
    }
};