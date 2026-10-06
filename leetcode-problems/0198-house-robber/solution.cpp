class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n==1) return nums[0];
        int a = 0;
        int b = nums[0];
        int c=0;
        for(int i = 2; i<=n; i++){
            c = max(nums[i-1]+a, b);
            a = b;
            b = c;
        }
        return c;
    }
};
