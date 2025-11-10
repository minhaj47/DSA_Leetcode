class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();

        int prev = INT_MAX, curr = 0, ans = 0;

        for(auto c: s){
            if(c == 'I') curr = 1;
            else if(c == 'V') curr = 5;
            else if(c == 'X') curr = 10;
            else if(c == 'L') curr = 50;
            else if(c == 'C') curr = 100;
            else if(c == 'M') curr = 1000;
            else if(c == 'D') curr = 500;

            cout << prev << " " << curr << endl;

            if(curr > prev) ans-=2*prev;

            ans+=curr;
            prev = curr;
        }
        return ans;
    }
};