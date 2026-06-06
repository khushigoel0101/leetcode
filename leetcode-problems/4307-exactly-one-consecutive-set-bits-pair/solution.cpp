class Solution {
public:
    bool consecutiveSetBits(int n) {
       int x = (n&(n>>1));
        if(x==0)return false;
        else return (x&(x-1)) == 0;
        
    }
};
