class Solution {
private:

    void dfs(int row, int col,
             vector<vector<char>>& grid,
             vector<vector<int>>& vis) {

        int n = grid.size();
        int m = grid[0].size();

        // mark visited
        vis[row][col] = 1;

        // 4 directions
        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        for(int k = 0; k < 4; k++) {

            int nr = row + delRow[k];
            int nc = col + delCol[k];

            // boundary + land + not visited
            if(nr >= 0 && nr < n &&
               nc >= 0 && nc < m &&
               grid[nr][nc] == '1' &&
               !vis[nr][nc]) {

                dfs(nr, nc, grid, vis);
            }
        }
    }

public:

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // visited array
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int count = 0;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                // new island found
                if(grid[i][j] == '1' && !vis[i][j]) {

                    count++;

                    dfs(i, j, grid, vis);
                }
            }
        }

        return count;
    }
};