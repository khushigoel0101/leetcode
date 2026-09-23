class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixpod(n,1), suffixprod(n,1), res(n);
        for(int i = 1; i<n; i++){
            prefixpod[i] = prefixpod[i-1]*nums[i-1];
        }
        for(int i = n-2; i>=0; i--){
            suffixprod[i] = suffixprod[i+1]*nums[i+1];
        }
        for(int i = 0; i<n; i++){
            res[i] = prefixpod[i]* suffixprod[i];
        }
        return res;
    }
};
