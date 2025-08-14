class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string s = "";
        int t = -1;
        for (int i = 0; i < n - 2; i++) {
            if (num[i] == num[i+1] && num[i+1] == num[i+2]) {
                string triple = string(3, num[i]);
                if (triple > s) { 
                    s = triple;
                    t = 1;
                }
            }
        }
        if (t == 1) {
            return s;
        } else {
            return s;
        }
    }
};

