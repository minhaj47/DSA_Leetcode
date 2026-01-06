class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sum;
        vector<int> count;
        helper(root, 0, sum, count);

        for(int i = 0; i < sum.size(); i++) {
            sum[i] /= count[i];
        }
        return sum;
    }

private:
    void helper(TreeNode* node, int level,
                vector<double>& sum, vector<int>& count) {
        if(!node) return;

        if(level == sum.size()) {
            sum.push_back(node->val);
            count.push_back(1);
        } else {
            sum[level] += node->val;
            count[level]++;
        }

        helper(node->left, level + 1, sum, count);
        helper(node->right, level + 1, sum, count);
    }
};
