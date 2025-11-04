class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        ans[0] = 1;
        cout << ans[0] << " ";
        for(int i=1; i<n; i++){   
            // here ith value will store the prefix till i-1 element
            // as we needs till i-1 for ith result
            ans[i] = ans[i-1] * nums[i-1];
            cout << ans[i] << " ";
        } cout << endl;
        int suffix_pro = 1;
        cout << suffix_pro << " ";
        for(int i=n-2; i>=0; i--){
            // here suffix_pro value will carry the suffix from i+1th element
            // as we needs from i+1 to n-1 for ith result
            suffix_pro = nums[i+1] * suffix_pro;
            ans[i] = ans[i] * suffix_pro;
            cout << suffix_pro << " ";
        } cout << endl;
        return ans;
    }
};