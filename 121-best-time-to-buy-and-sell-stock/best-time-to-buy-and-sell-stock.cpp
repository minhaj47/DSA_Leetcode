class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = INT_MIN, n = prices.size();
        int mxInd = n-1, mnInd = n-1;
        for(int i = n-1; i>=0; i--){
            int prof = prices[mxInd] - prices[i];
            // if(prof > mx){
            //     m
            // }
            mx = max(prof, mx);
            if(prof < 0)mxInd = i;
        }

        return mx;

    }
};