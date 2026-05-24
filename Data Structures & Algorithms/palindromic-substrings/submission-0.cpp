class Solution {
private:

    bool isPal(int l, int r, string &s) {

        // Base Case
        if(l >= r)
            return true;

        // Characters mismatch
        if(s[l] != s[r])
            return false;

        // Check inside substring
        return isPal(l + 1, r - 1, s);
    }

public:

    int countSubstrings(string s) {

        int n = s.length();

        int count = 0;

        // Generate all substrings
        for(int i = 0; i < n; i++) {

            for(int j = i; j < n; j++) {

                // Check palindrome
                if(isPal(i, j, s))
                    count++;
            }
        }

        return count;
    }
};