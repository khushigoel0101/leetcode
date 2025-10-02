class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int d = 0, emp =0;
        while(numBottles > 0 ){
            d = d+ numBottles;
            emp = emp + numBottles;
            numBottles = 0;
            if(emp>=numExchange){
                emp = emp - numExchange;
                numBottles++;
                numExchange++;
            }
        }
        return d;
    }
};
