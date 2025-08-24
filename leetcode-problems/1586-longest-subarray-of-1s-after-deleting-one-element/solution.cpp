class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, zeros = 0, m = 0;

        for (int j = 0; j < n; j++) {
            if (nums[j] == 0) zeros++;

            while (zeros > 1) {
                if (nums[i] == 0) zeros--;
                i++;
            }

            
            m = max(m, j - i);
        }

        return m;
    }
};

