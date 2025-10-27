class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int last = n-1, i = n-1;

        while(i>=0){
            if(nums[i] == val){
                swap(nums[i], nums[last]);
                last--;
            } 
            i--;
        }
        return last + 1;
    }
};