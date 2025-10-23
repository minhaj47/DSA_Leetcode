class Solution {
public:

    int funcNCR(int n, int r){
        long long ans = 1;
        for(int i=0; i<r; i++){
            ans*=(n-i);
            ans/=(i+1);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;

        for(int i=0; i<numRows; i++){
            vector<int>temp;
            for(int j=0; j<=i; j++){
                temp.push_back(funcNCR(i, j));
            } ans.push_back(temp);
        }
        return ans;
    }

};