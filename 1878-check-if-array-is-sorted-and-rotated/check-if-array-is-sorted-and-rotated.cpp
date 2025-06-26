class Solution {
    public:
        bool check(vector<int>& nums) {

            int n = nums.size(), cnt = 0;

            for(int i=0; i<n-1; i++){
                if(nums[i]>nums[i+1]){
                    cnt++;
                    if(nums[0]<nums[n-1])cnt++;
                }
            }

            if(cnt < 2)return true;
            return false;
        }
};