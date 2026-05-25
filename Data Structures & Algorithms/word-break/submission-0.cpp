class Solution {
private:

    bool fun(int i,
             string &s,
             vector<string>& wordDict,
             vector<int>& dp) {

        // Entire string segmented
        if(i == s.size())
            return true;

        // Already solved
        if(dp[i] != -1)
            return dp[i];

        // Try every word
        for(string word : wordDict) {

            int len = word.size();

            // Word matches current position
            if(i + len <= s.size() &&
               s.substr(i, len) == word) {

                // Recurse ahead
                if(fun(i + len,
                       s,
                       wordDict,
                       dp)) {

                    return dp[i] = true;
                }
            }
        }

        return dp[i] = false;
    }

public:

    bool wordBreak(string s,
                   vector<string>& wordDict) {

        int n = s.size();

        vector<int> dp(n, -1);

        return fun(0, s, wordDict, dp);
    }
};