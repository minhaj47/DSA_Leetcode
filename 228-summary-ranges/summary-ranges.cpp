class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            string range = "";
            range += to_string(nums[i++]); 
            int cnt = 0;
            while(i<n && nums[i] - 1 == nums[i-1]){
                i++;
                cnt++;
            } 
            i--;
            if(cnt) {
                range += "->";
                range += to_string(nums[i]);
            }
            ans.push_back(range);
        }
        return ans;
    }
};