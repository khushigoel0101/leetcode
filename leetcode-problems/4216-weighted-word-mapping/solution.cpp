class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        int m = weights.size();
        string s = "";
        for(string word: words){
            int sum = 0;
            for(char c : word){
               sum = sum +  weights[c-'a'];
            }
           sum = sum%26;
           s = s+ char('z'-sum);
        }
        return s;
    }
};
