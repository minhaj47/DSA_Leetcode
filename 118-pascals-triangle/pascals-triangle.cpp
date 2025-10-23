class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;

        for(int row=1; row<=numRows; row++){
            vector<int>temp;
            long long x = 1;
            temp.push_back(x);   // 1st element

            for(int col=1; col<row; col++){     // 2nd -> nth element
                x = x * (row - col);
                x/=col;
                temp.push_back(x);
            } ans.push_back(temp);
        }
        return ans;
    }
};
