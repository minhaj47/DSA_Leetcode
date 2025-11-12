class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        string ans = "";
        int n = s.size();
        int cycleLen = 2*numRows - 2;

        for(int r=0; r<numRows; r++){
            // process each zigzag: 1 vertical, 1 diagonal
            for(int i=r; i<n; i+=cycleLen){
                // vertical element
                ans+=s[i];
                // diagonal element
                int diagonalIdx = i + cycleLen - 2*r;
                if(r>0 && r<numRows-1 && diagonalIdx < n) {
                    ans+=s[diagonalIdx];
                }
            }
        }
        return ans;
    }
};