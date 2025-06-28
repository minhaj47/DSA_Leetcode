class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int n = nums.size(), cnt = 0, mx=0;

            for(int i=0; i<n; i++){
                if(nums[i]==0){
                    mx = max(cnt, mx);
                    cnt = 0;
                } 
                else cnt++;
            } mx = max(cnt, mx);

            return mx;
        }
    };