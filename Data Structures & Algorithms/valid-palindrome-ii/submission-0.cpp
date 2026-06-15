class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                int i = l + 1, j = r;
                while (i < j && s[i] == s[j]) {
                    i++;
                    j--;
                }
                if (i >= j) return true;
                i = l;
                j = r - 1;
                while (i < j && s[i] == s[j]) {
                    i++;
                    j--;
                }

                if(i >= j) return true;
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};