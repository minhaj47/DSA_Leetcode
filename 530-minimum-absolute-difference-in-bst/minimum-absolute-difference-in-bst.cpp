class Solution {
private: 
    void inorder(TreeNode* node, int& mn, int& prev) {
        if(!node) return;
        inorder(node->left, mn, prev);
        if(prev != -1) mn = min(mn, abs(prev - node->val));
        prev = node->val;
        inorder(node->right, mn, prev);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int mn = INT_MAX;
        int prev = -1;

        inorder(root, mn, prev);
        return mn;
    }
};