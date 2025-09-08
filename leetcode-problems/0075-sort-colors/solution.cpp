class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z = 0, o = 0, t = 0;

        for (int n : nums) {
            if (n == 0) z++;
            else if (n == 1) o++;
            else t++;
        }
        int i = 0;
        while (z--) nums[i++] = 0;
        while (o--) nums[i++] = 1;
        while (t--) nums[i++] = 2;
    }
};

