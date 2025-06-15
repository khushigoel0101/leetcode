class Solution {
public:
    string generateTag(string caption) {
        string s = "#";
        for (int i = 0; i < caption.length(); i++) {
            if (caption[i] != ' ') {
                s += tolower(caption[i]);
            } else {
                if (i + 1 < caption.length() && caption[i + 1] != ' ') {
                    if (s.length() == 1) {
                        s += tolower(caption[i + 1]);
                    } else {
                        s += toupper(caption[i + 1]);
                    }
                    i++;
                }
            }
        }
        return s.substr(0, 100);
    }
}
;
