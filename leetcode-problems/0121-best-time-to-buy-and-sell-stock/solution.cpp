class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, min_price = INT_MAX;
        for(int price: prices){
            if(min_price>price){
                min_price = price;
            }
            profit = max(price - min_price, profit);
        }
        return profit;
    }
};
