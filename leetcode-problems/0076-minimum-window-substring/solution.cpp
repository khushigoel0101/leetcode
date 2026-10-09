class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty()|| t.empty() || s.length()<t.length()) return "";
        int req = t.length();
        int minstr = 0;
        int l = 0, r = 0;
        int n = t.size();
        int min_size = INT_MAX;
        vector<int>cnt(128);
        for(char c: t){
            cnt[c]++;
        }
        while(r<s.length()){
          if(cnt[s[r]]>0){
            req--;
          }
          cnt[s[r]]--;
          r++;
          while(req == 0){
            if(r-l < min_size){
                min_size = r-l;
                minstr = l;
            }
            cnt[s[l]]++;
            if(cnt[s[l]]>0){
                req++;
            }
            l++;
          }
          
        }
        return min_size == INT_MAX ? "" : s.substr(minstr,min_size);
    }
};
/*
ADOBECODEBANC, t = ABC
map - freq of el of t
a - 1
b - 1
c - 1
ADOBECODEBANC
l
-r
a - 0
b - 0
c - 0

req = t.size

if found req--

req = 0
shrink window
if(s[l]in map>0)
l++
req++

aa, a



*/
