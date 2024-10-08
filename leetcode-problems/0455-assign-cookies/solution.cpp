class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int l = 0, r = 0,c=0;
        int n = g.size();
        int m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(l<n && r<m){
            if(s[r]>=g[l]){
                c++;
             l++;
            
            }
            r++;
        }
        return c;
    }
};

