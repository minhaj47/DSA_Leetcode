class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int>st;
        for(auto x: tokens) {
            if(x == "+" or x == "-" or x ==  "*" or x ==  "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if (x == "+") st.push(b + a);
                else if (x == "-") st.push(b - a);
                else if (x == "*") st.push(b * a);
                else st.push(b / a);
                continue;
            }
            st.push(stoi(x));
        }
        return st.top();
    }
};