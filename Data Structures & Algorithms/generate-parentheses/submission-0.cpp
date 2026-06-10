class Solution {
public:
    vector<string> ans;

    void backtrack(string curr, int open, int close, int n) {
        // If the string is complete
        if (curr.length() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // Add an opening bracket
        if (open < n) {
            backtrack(curr + "(", open + 1, close, n);
        }

        // Add a closing bracket if valid
        if (close < open) {
            backtrack(curr + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return ans;
    }
};