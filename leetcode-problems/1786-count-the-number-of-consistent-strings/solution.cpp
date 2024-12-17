class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> a(allowed.begin(), allowed.end());
        int c =0;
        for(int i =0; i<words.size(); i++){
            int f =0;
            for(int j = 0; j < words[i].size(); j++){
                char c = words[i][j];
                if (a.find(c) == a.end()) {
                    f = 1; break;
                }

            }
            if (f==0) {
                c++;
            }
        }
        return c;
    }
};
