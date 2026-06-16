class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

private:
    int atMostK(vector<int>& nums, int k) {
        if (k < 0) return 0;
        
        int n = nums.size();
        int l = 0, count = 0;
        vector<int> freq(n + 1, 0); 
        int distinct = 0;

        for (int r = 0; r < n; r++) {
            if (freq[nums[r]] == 0) {
                distinct++;
            }
            freq[nums[r]]++;

            while (distinct > k) {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0) {
                    distinct--;
                }
                l++;
            }

            count += (r - l + 1);
        }

        return count;
    }
};
