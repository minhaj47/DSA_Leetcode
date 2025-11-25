class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        for(string s: strs){
            string t = s;
            sort(s.begin(), s.end());
            mp[s].push_back(t);
        } 
        vector<vector<string>> ans;
        for(auto [key, value]: mp) {
            ans.push_back(value);
        }
        return ans;
    }
};