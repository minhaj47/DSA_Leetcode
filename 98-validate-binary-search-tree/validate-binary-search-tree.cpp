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
private: 
    long long prev = LLONG_MIN;
    bool ans = true;
    void helper(TreeNode* node) {
        if(!node || !ans) return;
        helper(node->left);
        if(prev >= node->val) {
            ans = false;
            return;
        }
        prev = node->val;
        helper(node->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        helper(root);
        return ans;
    }
}; 