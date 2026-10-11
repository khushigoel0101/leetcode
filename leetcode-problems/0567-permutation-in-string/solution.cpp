class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1hash(26, 0);
        vector<int> s2hash(26, 0);
        int n = s1.length();
        int m = s2.length();
        
        if (n > m) return false;
        
        // Build s1 frequency map
        for (char c : s1) {
            s1hash[c - 'a']++;
        }
        
        int l = 0;
        for (int r = 0; r < m; r++) {
            // Add current character to the window
            s2hash[s2[r] - 'a']++;
            
            // If window size exceeds s1 length, shrink from the left
            if (r - l + 1 > n) {
                s2hash[s2[l] - 'a']--;
                l++;
            }
            
            // Check if frequencies match
            if (s1hash == s2hash) {
                return true;
            }
        }
        
        return false;
    }
};
