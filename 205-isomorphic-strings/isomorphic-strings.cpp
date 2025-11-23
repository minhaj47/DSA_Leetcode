class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int>ms;
        unordered_map<char, int>mt;
        int n = s.size();
        if(n != t.size()) return false;

        for(int i=0; i<n; i++) {

            if(ms.count(s[i]) && ms[s[i]] != t[i]) return false;
            if(mt.count(t[i]) && mt[t[i]] != s[i]) return false;
            
            // map one to another
            ms[s[i]] = t[i];
            mt[t[i]] = s[i];
        }
        return true;
    }
};