class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Frequency array to track characters inside our current window
        vector<int> count(256, 0);
        
        int l = 0;
        int r = 0;
        int max_len = 0;
        int n = s.length();
        
        while (r < n) {
            // Add the current character to our window count
            count[s[r]]++;
            
            // If the character count becomes greater than 1, we have a duplicate!
            // Shrink the window from the left until count[s[r]] is back to 1
            while (count[s[r]] > 1) {
                count[s[l]]--; // Remove the element at 'l' from the window
                l++;           // Move left pointer forward
            }
            
            // At this point, the window from l to r is guaranteed to be unique
            max_len = max(max_len, r - l + 1);
            
            // Move the right pointer forward
            r++;
        }
        
        return max_len;
    }
};