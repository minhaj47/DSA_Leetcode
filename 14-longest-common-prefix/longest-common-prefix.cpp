class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) return "";

        string lcp = strs[0];
        int ansInd = lcp.size() - 1;

        for (int i = 1; i < n && ansInd >= 0; i++) {
            int l = min((int)strs[i].size(), ansInd + 1);

            int j = 0;
            while (j < l && strs[i][j] == lcp[j]) {
                j++;
            }

            ansInd = j - 1; // update prefix end index

            if (ansInd < 0) break; // no prefix left
        }

        return lcp.substr(0, ansInd + 1);
    }
};
