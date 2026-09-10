
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        // Allocate space for up to n houses
        vector<int> t(n + 1, 0); 
        
        // Case 1: Take from 1st House
        t[0] = 0;
        t[1] = nums[0];
        for (int i = 2; i <= n - 1; i++) {
            t[i] = max(t[i - 1], nums[i - 1] + t[i - 2]);
        }
        int result1 = t[n - 1];

        fill(t.begin(), t.end(), 0);

        // Case 2: Skip 1st House
        t[0] = 0; 
        t[1] = 0; // 0 houses taken from this range yields 0
        t[2] = nums[1]; // Taking just the second house
        for (int i = 3; i <= n; i++) {
            t[i] = max(t[i - 1], nums[i - 1] + t[i - 2]);
        }
        int result2 = t[n];

        return max(result1, result2);
    }
};

