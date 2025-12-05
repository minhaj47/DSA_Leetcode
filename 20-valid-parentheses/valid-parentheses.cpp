class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char x: s) {
            if(x == '(' or x == '{' or x == '[') {
                st.push(x);
            } else {
                if(st.empty()) return false;
                char c = st.top();
                st.pop();
                if((x == ')' and c != '(') || 
                (x == '}' and c != '{') || 
                (x == ']' and c != '[')) return false;
            }
        }
        return st.empty();
    }
};