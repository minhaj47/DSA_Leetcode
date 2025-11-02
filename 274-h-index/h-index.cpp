class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int>count(n+1, 0);   
        // count array relates to citation counts, not paper indices.

        for(auto x: citations){
            if(x>n){
                count[n]++;
            } else count[x]++;
        }

        int total = 0;

        for(int i = n; i>=0; i--){
            total+=count[i];
            if(total >= i){
                return i;
            }
        }
        return 0;
    }
};