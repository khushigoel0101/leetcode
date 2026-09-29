class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());
        int mx = 0;
        int n = nums.size(); 
        int left = 0;
        long long cost = 0; 
        for(int right = 0; right<n; right++){
            int mid = (left+right)/2;
            cost += nums[right] - nums[mid];
            while(cost>k){
                cost -= nums[(left+right+1)/2] - nums[left];
                left++;
            }
            mx = max(mx, right - left + 1);
        }
        return mx;
    }
};
