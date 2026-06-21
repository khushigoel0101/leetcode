class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(),costs.end());
        int i = 0,c=0;
        while(i<n && coins>0){
            coins = coins - costs[i];
            if(coins>=0){
                c++;
            }
            i++;
        }
        return c;
    }
};
