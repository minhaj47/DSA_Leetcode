class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int>ans;
        int n = words.size(), m = words[0].size();
        int total = n * m;
        int l = s.size();
        if(s.size() < total) return ans;

        unordered_map<string, int>freq;
        for(string x: words) freq[x]++;

        for(int offset = 0; offset < m; offset++) {
            int start = offset, cnt = 0;
            unordered_map<string, int> seen;
            for(int i = offset; i + m <= l; i+=m) {
                string word = s.substr(i, m);

                if(freq.count(word) != 0){
                    seen[word]++;
                    cnt++;
                
                    // If seen more times then freq, shrink from left
                    while(seen[word] > freq[word]) {
                        string startWord = s.substr(start, m);
                        seen[startWord]--;
                        start += m;
                        cnt--;
                    }

                    // if valid window found
                    if(cnt == n) {
                        ans.push_back(start);
                        // shrink to look for next
                        string startWord = s.substr(start, m);
                        seen[startWord]--;
                        start += m;
                        cnt--;
                    }

                } else {
                    // invalid word --> reset window after the invalid word
                    seen.clear();
                    cnt = 0;
                    start = i+m;
                }
            }
        }

        return ans;

    }
};