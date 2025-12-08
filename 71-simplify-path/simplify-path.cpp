class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string>st;

        for(int i=0; i<n; i++) {
            // skip the slashes
            while(i<n && path[i] == '/')i++;

            // collect word 
            string word = "";
            while(i<n && path[i] != '/') {
                word += path[i++];
            }
            
            if(word == "." or word == "") continue;
            if(word == ".."){
                if(!st.empty()) st.pop();
            } 
            else st.push(word);
        }

        string ans = "";
        while(!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return (ans == "") ? "/" : ans;
    }
};