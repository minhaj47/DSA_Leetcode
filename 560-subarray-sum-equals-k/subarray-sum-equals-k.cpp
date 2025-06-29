class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            int n = nums.size(), sum = 0;
            vector<int>prefix_sum(n+1);

            for(int i=0; i<=n; i++){
                prefix_sum[i]=sum;
                if(i<n)sum+=nums[i];
            }

            int ans = 0;

            for(int i=0; i<=n; i++){
                for(int j=i+1; j<=n; j++){
                    if(prefix_sum[j]-prefix_sum[i]==k)ans++;
                }
            }
            return ans;
        }
    };