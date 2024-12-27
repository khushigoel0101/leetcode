class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mpp;
        vector<string> result;
        string combined = s1 + " " + s2;
        string word = "";
        for (char c : combined) {
            if (c == ' ') {
                if (!word.empty()) {
                    mpp[word]++;
                    word = "";
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) {
            mpp[word]++;
        }
        for (const auto &entry : mpp) {
            if (entry.second == 1) {
                result.push_back(entry.first);
            }
        }

        return result;
    }
};

