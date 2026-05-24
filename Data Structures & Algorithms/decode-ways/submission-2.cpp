class Solution {
private:

    int fun(int i,
            string &s,
            vector<int>& dp) {

        // Successfully decoded
        if(i == s.size())
            return 1;

        // Invalid case
        if(s[i] == '0')
            return 0;

        // Already solved
        if(dp[i] != -1)
            return dp[i];

        // Take one digit
        int one = fun(i + 1, s, dp);

        int two = 0;

        // Take two digits
        if(i + 1 < s.size()) {

            int num =
                (s[i] - '0') * 10 +
                (s[i + 1] - '0');

            if(num >= 10 && num <= 26)
                two = fun(i + 2, s, dp);
        }

        return dp[i] = one + two;
    }

public:

    int numDecodings(string s) {

        int n = s.size();

        vector<int> dp(n, -1);

        return fun(0, s, dp);
    }
};