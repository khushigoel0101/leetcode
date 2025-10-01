class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ne = numBottles;  
        int t = ne;           
        int l = 0;           

        while (ne + l >= numExchange) {
            l += ne;                   
            ne = l / numExchange;      
            l = l % numExchange;       
            t += ne;                   
        }

        return t;
    }
};

