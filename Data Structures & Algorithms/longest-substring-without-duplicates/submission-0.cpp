class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>window;
        int l=0; int maxlen=0;
        for(int r=0; r<s.size(); r++){
            while(window.count(s[r])){
                window.erase(s[l]);
                l++;
            }
            window.insert(s[r]);

            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
    }
};
