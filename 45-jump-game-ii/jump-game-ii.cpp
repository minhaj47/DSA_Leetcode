class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, l = 0, r = 0;
        int n = nums.size();

        while(r<n-1){
            int furthest = r;
            for(int i=l; i<=r; i++){
                furthest = max(furthest, i + nums[i]);
            }
            jumps++;
            r = furthest;
        } return jumps;
    }
};