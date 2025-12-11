class Solution {
public:
    int calculate(string s) {
        long long number = 0;
        long long result = 0;
        int sign = 1;

        stack<long long> st;

        for (char c : s) {
            if (isdigit(c)) {
                number = number * 10 + (c - '0');
            } 
            else if (c == '+') {
                result += number * sign;
                number = 0;
                sign = 1;
            } 
            else if (c == '-') {
                result += number * sign;
                number = 0;
                sign = -1;
            } 
            else if (c == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } 
            else if (c == ')') {
                result += number * sign;
                number = 0;

                int prevSign = st.top(); st.pop();
                long long prevResult = st.top(); st.pop();

                result = prevResult + prevSign * result;
            }
        }

        return result + number * sign;
    }
};
