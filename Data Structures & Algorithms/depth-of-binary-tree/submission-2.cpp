/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {
int count =0;
    // TreeeNode* node = root;
    queue<TreeNode*> q;
    q.push(root);
    if(root==nullptr) return 0;
    while(!q.empty()){
        int size= q.size();
        for(int i=0; i<size; i++){
             TreeNode* node = q.front();
        q.pop();
            // q.push(node);
            if(node->left !=nullptr){
                q.push(node->left);
            }
            if(node->right != nullptr){q.push(node->right);}
        }
count++;

    }
 return count;
    }
};
