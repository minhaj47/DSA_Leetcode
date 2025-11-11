class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size(), l = 0;
        int i= n-1;
        
        while(s[i] == ' '){
            i--;
        }

        while(i>=0){
            if(s[i] == ' ') break;
            l++;
            i--;
        }
        return l;
    }
};