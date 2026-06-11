class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>result;
        unordered_map<char, int>mpp;
        for(char c: p){
            mpp[c]++;
        }
        int l =0;
        int t = p.size();
        for(int r = 0; r<s.length();r++){
            if(mpp.count(s[r])){
                if(mpp[s[r]]>0){
                    t--;
                }
                mpp[s[r]]--;
            }
           
           if(r-l+1>p.size()){
            if(mpp.count(s[l])){
                if(mpp[s[l]]>=0){
                    t++;
                }
                mpp[s[l]]++;
            }
            l++;
           }
           if(t==0) result.push_back(l);
        }
        return result;
    }
};
