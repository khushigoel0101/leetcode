class Solution {
public:
    bool Ispossible(int mid, vector<int>& nums, vector<long long int>& prefix, long long int k, int n) {
        if (mid == 0) return false;
        int i = 0, j = mid - 1;
        while (j < n) {
            long long int idx = (i + j) / 2;
            long long int t = nums[idx];
            long long int l = 0, r = 0;
            
            if (idx == 0) {
                l = 0;
            } else {
                long long int left_sum = prefix[idx - 1] - (i > 0 ? prefix[i - 1] : 0);
                l = abs((1LL * (idx - i) * t) - left_sum);
            }
            
            long long int right_sum = prefix[j] - prefix[idx];
            r = abs((1LL * (j - idx) * t) - right_sum);
            
            if (l + r <= k) {
                return true;
            }
            i++;
            j++;
        }
        return false;
    }

    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<long long int> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + nums[i];

        int min_score = 1;
        int max_score = n;
        int result_score = 1;

        while (min_score <= max_score) {
            int mid = (min_score + max_score) / 2;

            if (Ispossible(mid, nums, prefix, k, n)) {
                result_score = mid;
                min_score = mid + 1;
            } else {
                max_score = mid - 1;
            }
        }

        return result_score;
    }
};
