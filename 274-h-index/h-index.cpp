class Solution {
public:
    int hIndex(vector<int>& citations) {
        int totalPapers = citations.size();
        vector<int> citationCount(totalPapers + 1, 0);

        for (int c : citations) {
            if (c >= totalPapers)
                citationCount[totalPapers]++;
            else
                citationCount[c]++;
        }

        int total = 0;
        // Traverse from high citation counts to low
        for (int i = totalPapers; i >= 0; i--) {
            total += citationCount[i];
            if (total >= i)
                return i;
        }

        return 0;
    }
};