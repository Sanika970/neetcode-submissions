#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Check whether substring s[l...r] is palindrome
    bool isPal(int l, int r, string& s) {

        // Base Case
        if(l >= r)
            return true;

        // Characters do not match
        if(s[l] != s[r])
            return false;

        // Check inside substring
        return isPal(l + 1, r - 1, s);
    }

    string longestPalindrome(string s) {

        int n = s.size();

        int maxLen = 0;
        int start = 0;

        // Try all substrings
        for(int i = 0; i < n; i++) {

            for(int j = i; j < n; j++) {

                // Check palindrome
                if(isPal(i, j, s)) {

                    int len = j - i + 1;

                    // Update answer
                    if(len > maxLen) {
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};