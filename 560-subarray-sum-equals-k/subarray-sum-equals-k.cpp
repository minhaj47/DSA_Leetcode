class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            int n = nums.size(), sum = 0, ans = 0;

            unordered_map<int, int>freq; // <total, freq>
            freq[0]=1;

            for(auto x: nums){
                sum+=x;
                ans+=freq[sum-k];
                freq[sum]++;
            }
            return ans;
        }
    };