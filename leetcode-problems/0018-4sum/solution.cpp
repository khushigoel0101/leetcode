class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        int eleft = 0;
        while (eleft < n - 3) {
            if (eleft > 0 && nums[eleft] == nums[eleft - 1]) { eleft++; continue; }

            int eright = n - 1;
            while (eright > eleft + 2) {
                if (eright < n - 1 && nums[eright] == nums[eright + 1]) { eright--; continue; }

                int ileft = eleft + 1, iright = eright - 1;
                while (ileft < iright) {
                    long long sum = (long long)nums[eleft] + nums[eright] + nums[ileft] + nums[iright];
                    if (sum == target) {
                        result.push_back({nums[eleft], nums[ileft], nums[iright], nums[eright]});
                        while (ileft < iright && nums[ileft] == nums[ileft + 1]) ileft++;
                        while (ileft < iright && nums[iright] == nums[iright - 1]) iright--;
                        ileft++;
                        iright--;
                    } else if (sum < target) {
                        ileft++;
                    } else {
                        iright--;
                    }
                }
                eright--;
            }
            eleft++;
        }
        return result;
    }
};
