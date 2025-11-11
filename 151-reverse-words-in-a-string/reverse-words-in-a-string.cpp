class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int l = s.size(), k = 0;       

        for(int i = 0; i<l; i++){
            // find the first index of a word by ignoring the blank spaces using i
            while(i<l && s[i] == ' ')i++;

            // add a blank space if not the first word
            if(i != l && k>0) s[k++] = ' ';

            int start_idx = k;
            // forward the word using k
            while(i<l && s[i] != ' ') s[k++] = s[i++];

            reverse(s.begin() + start_idx, s.begin() + k);
        }
        s.resize(k);

        return s;    
    }
};