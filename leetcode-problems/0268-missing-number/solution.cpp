class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            if (nums[i] == n-1) {
                i++;
            } else {
                if (nums[i]<n && nums[i] != nums[nums[i]]) {
                    swap(nums[i], nums[nums[i]]);
                } else {
                    i++;
                }
            }
        }
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                ans = i;
                break;
            }
        }
       return ans>=0?ans:n;
    }
};
