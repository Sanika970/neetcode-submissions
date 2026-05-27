class Solution {
public:

    void dfs(int row, int col, vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        board[row][col] = '#';

        int delr[4] = {-1,0,1,0};
        int delc[4] = {0,-1,0,1};

        for(int i=0; i<4; i++) {

            int nrow = row + delr[i];
            int ncol = col + delc[i];

            if(nrow >= 0 && nrow < n &&
               ncol >= 0 && ncol < m &&
               board[nrow][ncol] == 'O') {

                dfs(nrow, ncol, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        // top and bottom rows
        for(int j=0; j<m; j++) {

            if(board[0][j] == 'O')
                dfs(0, j, board);

            if(board[n-1][j] == 'O')
                dfs(n-1, j, board);
        }

        // left and right columns
        for(int i=0; i<n; i++) {

            if(board[i][0] == 'O')
                dfs(i, 0, board);

            if(board[i][m-1] == 'O')
                dfs(i, m-1, board);
        }

        // final conversion
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {

                if(board[i][j] == 'O')
                    board[i][j] = 'X';

                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};