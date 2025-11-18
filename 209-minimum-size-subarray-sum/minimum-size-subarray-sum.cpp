class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0, ans = INT_MAX;
        while(i<n && j<n) {
            cout << "i: " << i << " j: " << j << " sum: " << sum << " ans: " << ans << endl; 
            if(sum>=target){
                ans = min(ans, j-i);
                sum -= nums[i++];
            } else {
                sum += nums[j++];
            } 
        } 
        while(sum>=target) {
            ans = min(ans, j-i);
            sum -= nums[i++];
        }
        return ans == INT_MAX ? 0 : ans;
    }
};