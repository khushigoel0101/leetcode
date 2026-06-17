class Solution {
public:
    string frequencySort(string s) {
       unordered_map<char, int> count;
       for(char c: s){
        count[c]++;
       }
       vector<pair<char,int>> freq(count.begin(), count.end());

       sort(freq.begin(), freq.end(), [&](pair<char,int>&p1, pair<char,int>p2){
        return p1.second>p2.second;
       });

      string result = "";
      for(auto& p: freq){
        result.append(p.second, p.first);
      }

      return result;

    }
};
