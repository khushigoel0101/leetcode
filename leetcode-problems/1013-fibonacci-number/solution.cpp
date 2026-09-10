class Solution {
public:
//Bottom up approach using constant space O(1)
//constant space is possible only bcz current space is dependent on just last two states
    int fib(int n) {
       if(n<=1)return n;
       int c;
       int a = 0, b = 1;
       for(int i = 2; i<=n; i++){
        c = a+b;
        a = b;
        b = c;
       } 
       return c;
    }
};
