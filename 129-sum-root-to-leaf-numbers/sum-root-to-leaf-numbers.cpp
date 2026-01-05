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
    int helper(TreeNode* root, int num) {
        if(!root) return 0;
        num*=10;
        num += root->val;
        if(!root->left && !root->right) {
            return num;
        }
        return helper(root->left, num) + helper(root->right, num);
    }
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
 
        return helper(root, 0);
    }
};