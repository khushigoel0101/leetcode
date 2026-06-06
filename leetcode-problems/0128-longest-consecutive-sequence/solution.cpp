class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxlen = 0;
        int count = 1;
        if (nums.size() == 0) {
            return 0;
        } else if (nums.size() == 1) {
            return 1;
        } else {
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] == nums[i + 1]) {
                    continue;
                } else if (nums[i] + 1 == nums[i + 1]) {
                    count++;
                } else {
                    maxlen = max(maxlen, count);
                    count = 1;
                }
            }
        }
        maxlen = max(maxlen, count);
        return maxlen;
    }
};
