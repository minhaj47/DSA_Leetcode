class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>um;
        int n = s.size(), m = t.size();
        if(n!=m) return false;

        for(int i=0; i<n; i++){
            um[s[i]]++;
            um[t[i]]--;
        }
        for(auto [key, value]: um) {
            if(value != 0)return false;
        }
        return true;
    }
};