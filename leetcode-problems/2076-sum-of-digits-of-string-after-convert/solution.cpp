class Solution {
public:
    int getLucky(string s, int k) {
        string p = "";
        for (char ch : s) {
            p.append(to_string(ch - 'a' + 1)); 
        }
        while (k-- > 0) {
            int sum = 0;
            for (char digit : p) {
                sum += digit - '0'; 
            }
            p = to_string(sum); 
        }
        return stoi(p); 
    }
};

