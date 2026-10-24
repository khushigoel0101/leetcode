class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        unordered_map<char,int>mpp;
        int maxlength = 0;
        while(r<s.length()){
           mpp[s[r]] ++;
           
           while(mpp[s[r]]>1){
             mpp[s[l]]--;
             l++;
            }
            maxlength = max(maxlength, r-l+1);
            r++;
        }
        return maxlength;
    }
};

/*
abcabcbb
-l
----r
map-
a - 1
b - 1
*/

