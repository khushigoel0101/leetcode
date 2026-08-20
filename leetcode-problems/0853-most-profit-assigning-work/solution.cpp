class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> arr;
        int n = difficulty.size();
        int m = worker.size();
        for(int i = 0; i< difficulty.size(); i++){
           arr.push_back({difficulty[i],profit[i]});
        }
        sort(arr.begin(), arr.end());

        for(int i = 1; i<n; i++){
            arr[i].second = max(arr[i].second,arr[i-1].second);
        }
         int tot = 0;
        
        for(int i = 0; i<m; i++){
            int cal = worker[i];
            int low = 0, high = arr.size()-1;
            int maxProfit = 0;
            while(low<=high){
               int mid = low + (high - low)/2;
               if(cal>=arr[mid].first){
                maxProfit = max(maxProfit, arr[mid].second);
                low = mid + 1;
               }else{
                high = mid -1;
               }
            }
            tot += maxProfit;
        }
        return tot;
    }
};
