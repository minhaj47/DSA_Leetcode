class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int>cnt;
        vector<int>ans;
        for(auto x: nums){
            cnt[x]++;
        }

        int n = nums.size();

        for(auto it: cnt){
            if(it.second > n/3)ans.push_back(it.first);
        }
        return ans;
    }
};
