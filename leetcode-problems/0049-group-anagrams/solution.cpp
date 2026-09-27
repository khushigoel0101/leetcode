class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //anagram is sorted form of the string
        //store the string in the value part and the sorted form as key
        unordered_map<string, vector<string>>m;
        for(string s:strs){
            string t = s;
            sort(t.begin(), t.end());
            m[t].push_back(s);
        }
        vector<vector<string>>res;
        for(auto pair: m){
            res.push_back(pair.second);
        }
        return res;
    }
};
