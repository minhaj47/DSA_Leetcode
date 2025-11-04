class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int isZero = 0;
        for(auto x: nums){
            if(x==0){
                isZero++;
                continue;
            }
            product*=x;
        }
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(isZero == 1 and nums[i]==0) {
                nums[i] = product;
            } else if(isZero) nums[i] = 0;
            else nums[i] = product/nums[i];
        }
        return nums;
    }
};