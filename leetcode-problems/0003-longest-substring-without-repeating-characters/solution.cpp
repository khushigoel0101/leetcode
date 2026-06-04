class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int c =0;
        int i =0 ;
        unordered_map<char,int>mpp;
        for(int j =0; j<n; j++){
            mpp[s[j]]++;
            while(mpp[s[j]] > 1){
                mpp[s[i]]--;
                i++;
            }
            c = max(c, j-i+1);
        }
        return c;

    }
};
