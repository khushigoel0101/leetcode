class Solution {
public:
    bool check(vector<int>& quantities, int mid, int n){
        int sum = 0;
        for(int i = 0; i<quantities.size(); i++){
            int c = (quantities[i] + mid -1)/mid;
            sum += c;
        }
        if(sum<=n)return true; else return false;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1; int high = *max_element(quantities.begin(),quantities.end());
        int res = 0;
        while(low<=high){
         int mid = low + (high - low)/2;
         if(check(quantities,mid,n)){
            res = mid; 
            high = mid -1;
         }else{
            low = mid + 1;
         }
        }
        return res;
    }
};
