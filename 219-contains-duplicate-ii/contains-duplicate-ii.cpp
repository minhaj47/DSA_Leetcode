class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0;
        unordered_map<int, int>mp;

        for(int i=0; i<n; i++) {
            if(mp[nums[i]]) return true;
            mp[nums[i]]++;

            if(i-start >= k){
                mp[nums[start]]--;
                start++;
            }
        }
        return false;
    }
};