class Solution {
private: 
    int mn = INT_MAX;
    int prev = -1;
public:
    int getMinimumDifference(TreeNode* root) {
        if(!root) return mn;
        getMinimumDifference(root->left);
        if(prev != -1) 
            mn = min(mn, abs(prev - root->val));
        prev = root->val;
        getMinimumDifference(root->right);
        return mn;
    }
};