class Solution {
public:
    bool hasCycle(ListNode *head) {

        unordered_map<ListNode*, int> mp;

        ListNode* temp = head;

        while (temp != nullptr) {

            if (mp[temp] > 0)
                return true;

            mp[temp]++;
            temp = temp->next;
        }

        return false;
    }
};