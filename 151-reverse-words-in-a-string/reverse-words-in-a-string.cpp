class Solution {
public:
    string reverseWords(string s) {
        string ans = "";

        for(int i = s.size() - 1; i>=0; i--){
            // skipping zero 
            while(i>=0 && s[i] == ' ')i--;
            if(i<0) break;

            // collect a word
            string word = "";
            while(i>=0 && s[i] != ' '){
                word+=s[i];
                i--;
            } 
            reverse(word.begin(), word.end());

            if(!ans.empty()) ans += " ";
            ans += word;
        }
        return ans;    
    }
};