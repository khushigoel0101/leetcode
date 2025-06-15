class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> l, r;
        long long res = 0;
        for (int num : nums) {
            r[num]++;
        }
        for (int j = 0; j < nums.size(); ++j) {
            r[nums[j]]--; 

            int x = nums[j] * 2;
            res = (res + 1LL * l[x] * r[x]) % MOD;

            l[nums[j]]++; 
        }

        return res;
    }
};

