class Solution {
private:
    vector<vector<bool>>visited;
    int m, n;
    void visit(vector<vector<char>>& grid, int i, int j) {
        if(i<0 || i>=m || j<0 || j>=n) return;
        if(grid[i][j] == '0' || visited[i][j]) return;

        visited[i][j] = true;
        
        visit(grid, i+1, j);
        visit(grid, i-1, j);
        visit(grid, i, j+1);
        visit(grid, i, j-1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        visited.assign(m, vector<bool>(n, false));
        int ans = 0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                char x = grid[i][j];
                if(x == '0' || visited[i][j] == true) continue;
                ans++;
                visit(grid, i, j);
            }
        }
        return ans;
    }
};