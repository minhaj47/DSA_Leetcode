class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            int idx = -1, n = nums.size();

            // 2 1 | 5 4 3 2 0 0 
            // idx = 1
            
            for(int i=n-1; i; i--){
                if(nums[i]>nums[i-1]){
                    idx = i-1;
                    break;
                }
            }
            
            if(idx == -1){
                reverse(nums.begin(), nums.end());
                return;
            }

            for(int j=n-1; j>idx; j--){
                if(nums[j]>nums[idx]){
                    swap(nums[j], nums[idx]);
                    break;
                }
            }
            
            reverse(nums.begin() + idx + 1, nums.end());
        }
};