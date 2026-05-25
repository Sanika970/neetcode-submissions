class Solution {
private:

    int fun(int i,
            int j,
            int m,
            int n,
            vector<vector<int>>& dp) {

        // Reached destination
        if(i == m - 1 && j == n - 1)
            return 1;

        // Out of bounds
        if(i >= m || j >= n)
            return 0;

        // Already solved
        if(dp[i][j] != -1)
            return dp[i][j];

        // Move down
        int down =
            fun(i + 1,
                j,
                m,
                n,
                dp);

        // Move right
        int right =
            fun(i,
                j + 1,
                m,
                n,
                dp);

        return dp[i][j] =
            down + right;
    }

public:

    int uniquePaths(int m,
                    int n) {

        vector<vector<int>> dp(
            m,
            vector<int>(n, -1)
        );

        return fun(0, 0, m, n, dp);
    }
};