class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> counts; 
        int l = 0;
        int max_count = 0;
        int max_len = 0;

        for (int r = 0; r < s.length(); r++) {
            counts[s[r]]++;
            max_count = max(max_count, counts[s[r]]);
            if ((r - l + 1) - max_count > k) {
                counts[s[l]]--;
                l++;
            }

            max_len = max(max_len, r - l + 1);
        }

        return max_len;
    }
};
