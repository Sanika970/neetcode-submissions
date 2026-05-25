class Solution {
private:
    int fun(int i, int j, string &word1, string &word2,
            vector<vector<int>> &dp) {

        // If word1 finished, insert remaining chars of word2
        if (i == word1.size())
            return word2.size() - j;

        // If word2 finished, delete remaining chars of word1
        if (j == word2.size())
            return word1.size() - i;

        if (dp[i][j] != -1)
            return dp[i][j];

        // If characters match
        if (word1[i] == word2[j]) {
            return dp[i][j] = fun(i + 1, j + 1, word1, word2, dp);
        }

        // Operations
        int del = 1 + fun(i + 1, j, word1, word2, dp);
        int insert = 1 + fun(i, j + 1, word1, word2, dp);
        int replace = 1 + fun(i + 1, j + 1, word1, word2, dp);

        return dp[i][j] = min({del, insert, replace});
    }

public:
    int minDistance(string word1, string word2) {

        vector<vector<int>> dp(word1.size(),
                               vector<int>(word2.size(), -1));

        return fun(0, 0, word1, word2, dp);
    }
};