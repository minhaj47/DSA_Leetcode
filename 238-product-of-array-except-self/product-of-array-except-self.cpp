class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n);
        prefix[0] = 1;
        cout << prefix[0] << " ";
        for(int i=1; i<n; i++){   
            // here ith value will store the prefix till i-1 element
            // as we needs till i-1 for ith result
            prefix[i] = prefix[i-1] * nums[i-1];
            cout << prefix[i] << " ";
        } cout << endl;
        vector<int>suffix(n);
        suffix[n-1] = 1;
        cout << suffix[n-1] << " ";
        for(int i=n-2; i>=0; i--){
            // here ith value will store the suffix from i+1 element
            // as we needs from i+1 to n-1 for ith result
            suffix[i] = suffix[i+1] * nums[i+1];
            cout << suffix[i] << " ";
        } cout << endl;

        vector<int>ans(n);

        for(int i=0; i<n; i++){
            ans[i] = suffix[i]*prefix[i];
        }

        return ans;

    }
};