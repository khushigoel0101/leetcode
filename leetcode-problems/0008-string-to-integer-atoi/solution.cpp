class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int sign = 1; long res = 0, idx = 0;
        while(idx <s.length() && s[idx] == ' '){
            idx++;
        }
        if(s[idx]=='-'){
            sign = -1;
            idx++;
        }else if(s[idx] == '+'){
            idx++;
        }

        while(idx<s.length() && isdigit(s[idx])){
            res = res*10 + (s[idx] - '0');

            if(sign* res>INT_MAX) return INT_MAX;
            if(sign * res <INT_MIN)return INT_MIN;
            idx++;
        }
        return (int)(sign * res);
    }
};
