class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        for (int len = n; len > 0; len--) {
            for (int start = 0; start <= n - len; start++) {
                int end = start + len - 1;
                if (isPalindrome(s, start, end)) {
                    return s.substr(start, len);
                }
            }
        }
        return "";
    }

private:
    bool isPalindrome(const string& s, int i, int j) {
        if (i >= j) return true;            
        if (s[i] != s[j]) return false;      
        return isPalindrome(s, i + 1, j - 1); 
    }
};
