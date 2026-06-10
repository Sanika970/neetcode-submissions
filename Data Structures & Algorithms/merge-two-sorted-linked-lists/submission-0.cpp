class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        priority_queue<int, vector<int>, greater<int>> p;

        while (list1 != nullptr) {
            p.push(list1->val);
            list1 = list1->next;
        }

        while (list2 != nullptr) {
            p.push(list2->val);
            list2 = list2->next;
        }

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (!p.empty()) {
            temp->next = new ListNode(p.top());
            p.pop();
            temp = temp->next;
        }

        return dummy->next;
    }
};