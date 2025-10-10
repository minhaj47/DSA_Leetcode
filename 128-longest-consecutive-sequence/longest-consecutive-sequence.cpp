class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size(), ans = 0, cnt = 1;

        if(n==0) return 0;

        for(int i=0; i<n-1; i++){
            if(nums[i + 1] - nums[i] == 0);
            else if(nums[i + 1] - nums[i] == 1)cnt++;
            else {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }

        ans = max(ans, cnt);

        return ans;
        
    }
};
