class Solution {
public:
    string minWindow(string s, string t) {
        // Map to store frequency of characters in t
        unordered_map<char, int> mpp;
        for (char a : t) {
            mpp[a]++;
        }
        
        int remaining = t.size();
        int left = 0;
        int min_len = INT_MAX;
        int start_idx = 0; // Tracks the start of our best window
        
        for (int r = 0; r < s.length(); r++) {
            
            if (mpp.count(s[r])) {
                if (mpp[s[r]] > 0) {
                    remaining--;
                }
                mpp[s[r]]--; 
            }
            
           
            while (remaining == 0) {
                
                if (r - left + 1 < min_len) {
                    min_len = r - left + 1;
                    start_idx = left;
                }
                
                if (mpp.count(s[left])) {
                    mpp[s[left]]++;
                    if (mpp[s[left]] > 0) {
                        remaining++;
                    }
                }
                left++;
            }
        }
        
        return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
    }
};
