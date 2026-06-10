class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>result;
        int n = s.length();
        if (s.length() < 10) return result;
        unordered_map<string, int>mpp;
        for(int i = 0; i<=s.length()-10; i++ ){
           string sub = s.substr(i, 10);
           mpp[sub]++;
          if(mpp[sub] == 2){
            result.push_back(sub);
          }
        }
        return result;
    }
};
