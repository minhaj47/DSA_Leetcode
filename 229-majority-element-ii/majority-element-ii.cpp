class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1 = INT_MIN, el2 = INT_MIN;
        int cnt1 = 0, cnt2 = 0;

        for(auto x: nums){
            if(cnt1 == 0 && x != el2){
                el1 = x;
                cnt1 = 1;
            } else if(cnt2 == 0 && x != el1){
                el2 = x;
                cnt2 = 1;
            } else if(el1 == x){
                cnt1++;
            } else if(el2 == x){
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        cnt1 = 0, cnt2 = 0;

        for(auto x: nums){
            if(x == el1){
                cnt1++;
            } else if(x == el2){
                cnt2++;
            }
        }       
        if(cnt1>nums.size()/3)ans.push_back(el1);
        if(cnt2>nums.size()/3)ans.push_back(el2);

        return ans;
    }
};
