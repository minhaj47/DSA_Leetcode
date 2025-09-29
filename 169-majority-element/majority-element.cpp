class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int me = nums[0], cnt = 0;

        for(auto x: nums){
            if(cnt == 0){
                me=x;
            }
            if(x==me){
                cnt++;
            } else cnt--;
        }

        cnt = 0;

        for(auto x: nums){
            if(x==me)cnt++;
        }

        if(cnt>nums.size()/2)return me;

        return -1;
    }
}; 