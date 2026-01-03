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
    bool symmetricTraversal(TreeNode* l1, TreeNode* l2) {
        if(!l1 && !l2) return true;
        if(!l1 || !l2 || l1->val != l2->val) return false;
        
        return symmetricTraversal(l1->left, l2->right) && 
            symmetricTraversal(l1->right, l2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        
        return symmetricTraversal(root->left, root->right);
    }
};