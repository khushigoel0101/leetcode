class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        long long res = 0;
        while(temp>0){
           res = res*10 + (temp%10);
           temp /= 10;
        }
        if((int)res == x) return true;
        else return false;
    }
};
