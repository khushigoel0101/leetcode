class Solution {
public:
    int strStr(string haystack, string needle) {
        int res = -1;
        int l = 0;
        int r = 0;
        int n = haystack.size();
        int m = needle.size();
        while(r<=n-m){
          if(haystack[r] == needle[0]){
            string s = haystack.substr(r,needle.size());
            if(s == needle){
                return r;
            }
          }
          r++;
        }
        return res;
    }
};


