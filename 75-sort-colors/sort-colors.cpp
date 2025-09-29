
class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(auto x: nums){
            mp[x]++;
        }

        int n = nums.size();

        for(int j=0, i=0; i<n; j++){
            while(mp[j]--){
                nums[i++]=j;
            }
        }
        
    }
};
