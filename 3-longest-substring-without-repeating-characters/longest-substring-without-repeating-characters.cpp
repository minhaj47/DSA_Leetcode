class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mp;

        int left = 0, ans = INT_MIN;
        int n = s.size();
        if(n == 0) return 0;

        for(int right=0; right<n; right++){
            while(mp[s[right]]){
                mp[s[left++]]--;
            }
            ans = max(ans, right - left + 1); 
            mp[s[right]]++;
        }
        return ans;
    }
};