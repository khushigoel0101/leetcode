class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>res;
        int req = p.length();;
        if(s.empty() || p.empty() || s.length()<p.length()){
            return {};
        }
        vector<int>cnt(26);
        for(int i = 0; i<p.length(); i++){
            cnt[p[i]-'a']++;
        }
        int l = 0, r = 0;
        while(r<s.length()){
            if(cnt[s[r]-'a']>0){
                req--;
            }
            cnt[s[r]-'a']--;

            if(req==0){
                res.push_back(l);
            }

            if(r-l+1 == p.length()){
                if(cnt[s[l]-'a']>=0){
                    req++;
                }
                cnt[s[l]-'a']++;
                l++;
            }
            r++;
        }
        return res;
    }
};
/*
cbaebabacd
req = 3-2-1-0, 

*/
