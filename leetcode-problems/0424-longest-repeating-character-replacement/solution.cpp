class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l = 0, r = 0;
        int maxcnt = 0, maxfreq = 0;
        vector<int>cnt(26);
        while(r<n){
            cnt[s[r]-'A']++;
            maxfreq = max(maxfreq,  cnt[s[r]-'A']);
            if((r-l+1) - maxfreq >k ){
                cnt[s[l]-'A']--;
                l++;
            }
            maxcnt = max(maxcnt,r-l+1);
            r++;
        }
        return maxcnt;
    }
};
/*
AABABBA, k= 2
l
-----r
map - a - 3
b-1
most_freq_el = 3, cnt = r - l + 1 = 4
non_rep_cnt = 1
*/
