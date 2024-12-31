class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {

        while (k>0) {
            int n = nums.size();
            int m = INT_MAX, mi = 0;

            for (int i = 0; i<n; i++) {
                if (nums[i] < m) {
                    m = nums[i];
                    mi = i;
                }
            }
            nums[mi]=m*multiplier;
            k--;
        }
        return nums;
    }
};
