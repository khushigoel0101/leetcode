class Solution {
public:
    int reverse(int x) {
        long long n = x; long long r = 0;
        if(n<0){
            n = abs(n);
        }
        while(n>0){
            int d = n%10;
            r = (r*10) + d;
            n = n/10;
        }

       if(x<0){
        if(-r<INT_MIN){return 0;}else{return -r;}
       }else{
        if(r>INT_MAX){return 0;}else{return r;}
       }
    }
};
