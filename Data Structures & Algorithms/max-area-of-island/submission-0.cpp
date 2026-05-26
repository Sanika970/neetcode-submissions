class Solution {
private:

    void dfs(int row, int col,
             int &area,
             vector<vector<int>>& grid,
             vector<vector<int>>& vis) {

        vis[row][col] = 1;
        area++;

        int n = grid.size();
        int m = grid[0].size();

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++) {

            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            // boundary first
            if(nrow >= 0 && nrow < n &&
               ncol >= 0 && ncol < m &&
               grid[nrow][ncol] == 1 &&
               !vis[nrow][ncol]) {

                dfs(nrow, ncol, area, grid, vis);
            }
        }
    }

public:

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int ans = 0;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                // start DFS only from new land
                if(grid[i][j] == 1 && !vis[i][j]) {

                    int area = 0;

                    dfs(i, j, area, grid, vis);

                    ans = max(ans, area);
                }
            }
        }

        return ans;
    }
};