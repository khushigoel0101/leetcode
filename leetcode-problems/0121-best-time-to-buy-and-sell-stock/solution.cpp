class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, min_price = INT_MAX;
        for(int price: prices){
            if(price<min_price){
                min_price = price;
            }
            profit = max(profit, price-min_price);
        }
        return profit;
    }
};
