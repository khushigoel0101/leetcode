class Solution {
public:
    int robery(vector<int>& nums, int start, int end) {
        int len = end - start + 1;
        if (len <= 0) return 0;
        if (len == 1) return nums[start];
        
        vector<int> t(len, 0);
        t[0] = nums[start];
        t[1] = max(nums[start], nums[start + 1]);
        
        for (int i = 2; i < len; i++) {
            t[i] = max(nums[start + i] + t[i - 2], t[i - 1]);
        }
        
        return t[len - 1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        int choice1 = robery(nums, 0, n - 2);
        int choice2 = robery(nums, 1, n - 1);
        
        return max(choice1, choice2);
    }
};
