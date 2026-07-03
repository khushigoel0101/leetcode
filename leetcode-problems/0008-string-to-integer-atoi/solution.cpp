class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0; int sign= 0;
        long long num = 0;
        while(s[i]==' '){
            i++;
        }

        if(s[i]=='-'|| s[i]=='+'){
           if(s[i]=='-'){sign = -1;} 
           i++;
        }
        
           while(s[i]=='0'){
             i++;
           } 
           while(i<n && isdigit(s[i])){
            num = num * 10 + (s[i]-'0');
            if(num>INT_MAX && sign == 0) return INT_MAX;
            if(sign == -1 && num>INT_MAX) return INT_MIN; 
            i++;
           }

           if(sign == -1) num = num *-1;
         return num;

    }
};
