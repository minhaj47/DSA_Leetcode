class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0, mn;

        for(int i=0; i<n; i++){
            if(i==0)mn=prices[0];
            else{
                mn = min(mn, prices[i-1]);
            }
            ans = max(ans, prices[i] - mn);
        }

        return ans;

    }
};