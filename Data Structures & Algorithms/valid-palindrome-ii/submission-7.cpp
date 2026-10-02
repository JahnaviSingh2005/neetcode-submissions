class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                int i = l + 1;
                int j = r;
                while (i < j && s[i] == s[j]) {
                    i++;
                    j--;
                }
                bool left = (i >= j);
                int x = l;
                int y = r - 1;
                while (x < y && s[x] == s[y]) {
                    x++;
                    y--;
                }
                bool right = (x >= y);
                return left || right;
            }
            l++;
            r--;
        }
        return true;
    }
};