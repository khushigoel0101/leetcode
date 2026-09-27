class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());
        int mx = 0;
        long long cost = 0;
        int left = 0;
        for(int right = 0; right<nums.size(); right++){
            cost += nums[right] - nums[(left+right)/2];
            while(cost>k){
                cost -= nums[(left+right+1)/2] - nums[left];
                left++;
            }
            mx = max(mx, right-left+1);
        }
        return mx;
    }
};
