class Solution {
public:
//we buy when we know next day is going to be profitable and vice versa
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int lmin = prices[0];
        int lmax = prices[0];
        int res = 0;
        int i = 0;
        while(i<n-1){
            //the point where the curr prices is lower than the price ahead
            //skip until curr is lower
           while(i<n-1 && prices[i]>=prices[i+1]){i++;}
           lmin = prices[i];
           //skip unit curr is greater
           while(i<n-1 && prices[i]<=prices[i+1]){
            i++;
           }
           lmax = prices[i];
           res = res + (lmax - lmin);
        }
        return res;
    }
};
