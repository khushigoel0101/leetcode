class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int tot = 0, maxsum = nums[0], curr = 0, minsum = nums[0], currmin = 0;
        for(int a: nums){
            curr = max(curr + a, a);
            maxsum = max(maxsum, curr);
            currmin = min(currmin+a, a);
            minsum = min(minsum, currmin);
            tot += a;
        }
        return maxsum > 0 ? max(maxsum, tot- minsum) : maxsum;
    }
};
