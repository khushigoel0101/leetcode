class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>ans;
        for(int i =0; i<(prices.size()-1);i++){
             int f =0;
            for(int j = i+1; j<prices.size(); j++){
                if(prices[j]<=prices[i]){
                    f = 1;
                    ans.push_back(prices[i]-prices[j]);
                    break;
                }
            }
            if(f==0){
                ans.push_back(prices[i]);
            }
        }
        ans.push_back(prices[prices.size()-1]);
        return ans;
    }
};
