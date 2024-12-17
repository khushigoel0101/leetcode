class Solution {
public:
    string makeFancyString(string s) {
        if (s.empty()) return s;

        string t = "";  
        int c = 1;  

        t += s[0];  

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                c++;
                if (c > 2) continue;
            } else {
                c = 1;  
            }

            t += s[i];  
        }

        return t;
    }
};

