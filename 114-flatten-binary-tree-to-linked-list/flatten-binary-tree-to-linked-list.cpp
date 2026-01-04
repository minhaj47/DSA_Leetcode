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
// private:
//     TreeNode* helper(TreeNode* root) {
//         if(!root) return nullptr;

//         TreeNode* leftTail = helper(root->left);
//         TreeNode* rightTail = helper(root->right);

//         if(root->left) {
//             TreeNode* temp = root->right;
//             root->right = root->left;
//             root->left = nullptr;
//             leftTail->right = temp;
//         }

//         return rightTail ? rightTail : (leftTail ? leftTail : root);
//     }
private: 
    void preorder(TreeNode* root, vector<TreeNode*>& nodes) {
        if(!root) return;
        nodes.push_back(root);
        preorder(root->left, nodes);
        preorder(root->right, nodes);
    }
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        vector<TreeNode*> nodes; 
        preorder(root, nodes);

        for(int i=0; i<nodes.size() - 1; i++) {
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i+1];
        }
    }
};