class Solution {
public:
    int smallestNumber(int n, int t) {
        int k = n;
        
        for(int i = n;; i++){
            int temp = k;
            int prod = 1;
           while(temp>0){
              prod = prod * (temp%10);
              temp = temp/10;
            }
            
            if(prod%t==0){
                break;
            }
            k++;
        }

        return k;

        
        
    }
};
