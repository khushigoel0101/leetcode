class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<int, string>> val;

        for (int i = 0; i < code.size(); i++) {
            if (code[i].empty()) continue;

            bool f = true;
            for (char c : code[i]) {
                if (!isalnum(c) && c != '_') {
                    f = false;
                    break; 
                }
            }
            if (!f) continue;

            int p = 0;
            if (businessLine[i] == "electronics")
                p = 1;
            else if (businessLine[i] == "grocery")
                p = 2;
            else if (businessLine[i] == "pharmacy")
                p = 3;
            else if (businessLine[i] == "restaurant")
                p = 4;

            if (p == 0) continue;

            if (!isActive[i]) continue;

            val.push_back({p, code[i]});
        }

        sort(val.begin(), val.end());

        vector<string> result;
        for (auto& v : val) {
            result.push_back(v.second);
        }

        return result;
    }
};

