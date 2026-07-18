class Solution {
public:
    int findGCD(vector<int>& nums) {
        ranges::sort(nums);
        int m = gcd(nums[0],nums[nums.size()-1]);
        return m;
    }
};
