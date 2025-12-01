class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int>st(nums.begin(), nums.end());
        int ans = 0;

        for(auto x: st) {
            if(st.find(x - 1) != st.end()) continue;
            int cnt = 1;
            while(st.find(++x) != st.end()) cnt++;
            ans = max(ans, cnt);
        }
        return ans;
    }
};
