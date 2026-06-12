class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;

        unordered_map<Node*, Node*> mp;

        Node* temp = head;

        // Create copy of every node
        while (temp != nullptr) {
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;

        // Connect next and random pointers
        while (temp != nullptr) {
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }

        return mp[head];
    }
};