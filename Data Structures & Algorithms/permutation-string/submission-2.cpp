class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        vector<int> s1Count(26, 0), s2Count(26, 0);
        
        // Fill the first window
        for (int i = 0; i < s1.length(); i++) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        // Slide the window across s2
        for (int i = 0; i < s2.length() - s1.length(); i++) {
            if (s1Count == s2Count) return true; // Direct vector comparison!
            
            // Move window: remove old character (left), add new character (right)
            s2Count[s2[i] - 'a']--;
            s2Count[s2[i + s1.length()] - 'a']++;
        }

        // Check the very last window position
        return s1Count == s2Count;
    }
};