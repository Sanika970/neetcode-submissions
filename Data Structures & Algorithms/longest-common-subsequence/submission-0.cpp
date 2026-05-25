class Solution {
private:

    int fun(int i,
            int j,
            string& text1,
            string& text2,
            vector<vector<int>>& dp) {

        // One string finished
        if(i == text1.size() ||
           j == text2.size())
            return 0;

        // Already solved
        if(dp[i][j] != -1)
            return dp[i][j];

        // Characters match
        if(text1[i] == text2[j]) {

            return dp[i][j] =
                1 + fun(i + 1,
                        j + 1,
                        text1,
                        text2,
                        dp);
        }

        // Skip from text1
        int one =
            fun(i + 1,
                j,
                text1,
                text2,
                dp);

        // Skip from text2
        int two =
            fun(i,
                j + 1,
                text1,
                text2,
                dp);

        return dp[i][j] =
            max(one, two);
    }

public:

    int longestCommonSubsequence(string text1,
                                 string text2) {

        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(
            n,
            vector<int>(m, -1)
        );

        return fun(0,
                   0,
                   text1,
                   text2,
                   dp);
    }
};