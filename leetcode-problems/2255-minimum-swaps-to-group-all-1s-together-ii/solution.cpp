class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int>rep(nums.begin(), nums.end());
        for(int i = 0; i<n-1; i++){
            rep.push_back(nums[i]);
        }
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(nums[i]==1){
                cnt++;
            }
        }
        int k = cnt;
        int l = 0; int r = 0;
        int mxone = 0;
        int curr = 0;
        while(r<rep.size()){
            if(rep[r]==1){
                curr++;
            }
            if(r-l+1==k){
               mxone = max(mxone, curr);
               if(rep[l]==1){
                curr--;
               }
               l++;
            }
            r++;
        }
        return cnt-mxone;
    }
};
