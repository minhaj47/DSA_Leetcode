class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int pos = 0, neg = 0;

        for(auto x: nums){
            if(x<0){
                ans[neg*2 + 1] = x;
                neg++;
            } else {
                ans[pos*2] = x;
                pos++;
            }
        }

        return ans;
    }
};