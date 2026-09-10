class Solution {
public:
    //space optimized version
    //things to remember -> prevprev = 0 initially and prev = nums[0], then fill 1 to n (following 0 
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int prevPrev = 0;
        int prev = nums[0];
        for (int i = 1; i < n; i++) {
            int skip = prev;
            int take = nums[i] + prevPrev;
            int current = max(skip, take);
            prevPrev = prev;
            prev = current;
        }

        return prev;
    }
};

