class Solution {
private:
    int m, n;
    void visit(vector<vector<char>>& grid, int i, int j) {
        if(i<0 || i>=m || j<0 || j>=n) return;
        if(grid[i][j] == '1') {
            grid[i][j] = '2';
        
            visit(grid, i+1, j);
            visit(grid, i-1, j);
            visit(grid, i, j+1);
            visit(grid, i, j-1);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ans = 0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                char x = grid[i][j];
                if(x == '1') {
                    ans++;
                    visit(grid, i, j);
                }
                
            }
        }
        return ans;
    }
};