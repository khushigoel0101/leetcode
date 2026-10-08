class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_p = 0;
        for(int i = 1; i<n; i++){
            if(prices[i-1]<prices[i]){
                max_p += (prices[i] - prices[i-1]);
            }
        }
        return max_p;
    }
};
