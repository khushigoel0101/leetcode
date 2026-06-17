class Solution {
public:
    int beautySum(string s) {
        int l = 0;
        int r = 0;
        int tot = 0;
        unordered_map<char,int>mpp;
        while(l<s.length()){
            r = l;
            int maxval = INT_MIN, minval = INT_MAX, beauty = 0;
            mpp.clear();
            while(r<s.length()){
             minval = INT_MAX;
              mpp[s[r]]++;
              maxval = max(maxval, mpp[s[r]]);
              for(auto it: mpp){
              minval = min(minval, it.second);
              }
              beauty = maxval-minval;
              tot = tot + beauty;
              r++;
            }
           l++;
        }
       return tot;
    }
};
