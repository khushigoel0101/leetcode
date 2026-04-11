class Solution {
public:
    bool subsetSum(vector<int>& nums, int sum){
        int n = nums.size();
        vector<vector<bool>> dp( n+1, vector<bool>(sum+1, false));
        for(int i =0; i<=n; i++){
            dp[i][0]=true;
        }
        for(int i =1; i<=n; i++){
            for(int j = 1; j<=sum; j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        for(int i =0; i<n; i++){
           sum = sum + nums[i];
        }
        if(sum%2 != 0)
        return false;

        else
        return subsetSum(nums, sum/2);
    }
};
