class Solution {
public:
    bool isHappy(int n) {
        if(n<=9){
            if(n==1 || n==7){
                return true;
            }else{
                return false;
            }
        }else{
            while(n>9){
                int t = n;
                int sum =0;
                while(t>0){
                    int s = t%10;
                    sum = sum + (s*s);
                    t = t/10;
                }
                n = sum;
            }
            if(n==1 || n==7){
                return true;
            }else{
                return false;
            }
        }
    }
};
