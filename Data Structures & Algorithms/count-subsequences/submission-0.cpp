class Solution {
private:

    int fun(int i,
            int j,
            string& s,
            string& t,
            vector<vector<int>>& dp) {

        // Entire t formed
        if(j == t.size())
            return 1;

        // s exhausted
        if(i == s.size())
            return 0;

        // Already solved
        if(dp[i][j] != -1)
            return dp[i][j];

        // Characters match
        if(s[i] == t[j]) {

            int take =
                fun(i + 1,
                    j + 1,
                    s,
                    t,
                    dp);

            int skip =
                fun(i + 1,
                    j,
                    s,
                    t,
                    dp);

            return dp[i][j] =
                take + skip;
        }

        // Characters don't match
        return dp[i][j] =
            fun(i + 1,
                j,
                s,
                t,
                dp);
    }

public:

    int numDistinct(string s,
                    string t) {

        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(
            n,
            vector<int>(m, -1)
        );

        return fun(0,
                   0,
                   s,
                   t,
                   dp);
    }
};