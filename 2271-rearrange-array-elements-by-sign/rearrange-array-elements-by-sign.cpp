class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>pos, neg;

        for(auto x: nums){
            if(x<0){
                neg.push_back(x);
            } else pos.push_back(x);
        }

        int a = 0, b = 0;
        for(int i=0; i<n; i++){
            nums[i] = (i&1)? neg[a++]: pos[b++];
        }

        return nums;
    }
};