class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = INT_MIN, s = 0;
        
        for(auto x: nums){
            s+=x;
            mx = max(s, mx);
            if(s<0){
                s=0;
            }
        }
        return mx;
    }
};