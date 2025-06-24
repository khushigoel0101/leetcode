class Solution {
public:
    bool isPalindrome(int x) {
        int n = x;
        long long r = 0;
        while(n>0){
            int d = n%10;
            r = (r*10) + d;
            n = n/10;
        }
        if(r==x){
          return true;
        }else{
            return false;
        }
    }
};
