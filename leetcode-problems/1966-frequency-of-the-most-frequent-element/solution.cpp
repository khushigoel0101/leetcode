class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        long long l = 0, r = 0;
        sort(nums.begin(), nums.end());
        long long maxfreq = 0;
        long long curr_sum = 0;
        while(r<n){
            curr_sum += nums[r];
            if(curr_sum +(long long)k < nums[r]*(r-l+1)){ // if what we have is less than want
                curr_sum -= nums[l];
                l++;
            }else{
                maxfreq = max(maxfreq, r-l+1);
            }
            r++;
        }
        return maxfreq;
    }
};
