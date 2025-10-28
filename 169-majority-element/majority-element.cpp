class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int me = nums[0], cnt = 1, n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i] == me){
                cnt++;
            } else cnt--;
            if(cnt == 0){
                me = nums[i];
                cnt = 1;
            }
        }
        return me;
    }
}; 