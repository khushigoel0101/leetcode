class Solution {
public:
    string frequencySort(string s) {
        //to sort an unordered_map,--
       unordered_map<char, int> count;
       for(char c: s){
        count[c]++;
       }
       //1. copy the map to a vector
       vector<pair<char,int>> freq(count.begin(), count.end());
      //2. to sort by values use .second and in decreasing order
       sort(freq.begin(), freq.end(), [&](const auto& p1, const auto& p2){
        return p1.second>p2.second;
       });

      string result = "";
      for(auto p: freq){
        result.append(p.second, p.first);
      }

      return result;

    }
};
