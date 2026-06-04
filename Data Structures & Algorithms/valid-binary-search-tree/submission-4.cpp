class Solution {
public:
    bool validate(TreeNode* node, long long low, long long high) {
        if (!node) return true;

        if (node->val <= low || node->val >= high)
            return false;

        return validate(node->left, low, node->val) &&
               validate(node->right, node->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};