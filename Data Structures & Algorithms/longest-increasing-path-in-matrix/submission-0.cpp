class Solution {
private:

    int fun(int i,
            int j,
            vector<vector<int>>& matrix,
            vector<vector<int>>& dp) {

        // Already solved
        if(dp[i][j] != -1)
            return dp[i][j];

        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 1;

        // Down
        if(i + 1 < n &&
           matrix[i + 1][j] >
           matrix[i][j]) {

            ans = max(ans,
                      1 + fun(i + 1,
                              j,
                              matrix,
                              dp));
        }

        // Up
        if(i - 1 >= 0 &&
           matrix[i - 1][j] >
           matrix[i][j]) {

            ans = max(ans,
                      1 + fun(i - 1,
                              j,
                              matrix,
                              dp));
        }

        // Right
        if(j + 1 < m &&
           matrix[i][j + 1] >
           matrix[i][j]) {

            ans = max(ans,
                      1 + fun(i,
                              j + 1,
                              matrix,
                              dp));
        }

        // Left
        if(j - 1 >= 0 &&
           matrix[i][j - 1] >
           matrix[i][j]) {

            ans = max(ans,
                      1 + fun(i,
                              j - 1,
                              matrix,
                              dp));
        }

        return dp[i][j] = ans;
    }

public:

    int longestIncreasingPath(
        vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(
            n,
            vector<int>(m, -1)
        );

        int ans = 0;

        // Every cell can start path
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                ans = max(ans,
                          fun(i,
                              j,
                              matrix,
                              dp));
            }
        }

        return ans;
    }
};