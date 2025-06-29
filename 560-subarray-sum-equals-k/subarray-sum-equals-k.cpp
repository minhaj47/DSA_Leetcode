class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            int n = nums.size(), sum = 0, ans =0;
            vector<int>prefix_sum;

            for(int i=0; i<n; i++){
                prefix_sum.push_back(sum);
                if(i<n)sum+=nums[i];
                int cnt = count(prefix_sum.begin(), prefix_sum.end(), sum-k);
                if(cnt>0){
                    // cout << i << " :" << cnt << " " << sum << " " << k << " ";
                    ans+=cnt;
                }
            }

            return ans;
        }
    };
