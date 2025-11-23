class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string>mp;
        unordered_map<string, char>mt;
        int n = pattern.size();
        int m = s.size(), j = 0;

        for(int i=0; i<n; i++) {
            
            string word = "";

            while(j<m && s[j] != ' '){
                word+=s[j++];
            } j++;

            if(word == "") return false;

            if(mp.count(pattern[i]) && mp[pattern[i]] != word) return false;
            if(mt.count(word) && mt[word] != pattern[i]) return false;
            
            // map one to another
            mp[pattern[i]] = word;
            mt[word] = pattern[i];
        }
        if(j<m) return false;
        return true;
    }
};

