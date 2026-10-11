class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size();
       long long currsum = 0, maxsum = 0;
       unordered_map<int, int>freq;
        while(r<n){
            currsum += nums[r];
            freq[nums[r]]++;
            if(r-l+1>k){
                currsum -= nums[l];
                freq[nums[l]]--;
                if(freq[nums[l]]==0){
                    freq.erase(nums[l]);
                }
                l++;
            }
            //check if map size is same as window size - all elements are distinct
            if(r-l+1 ==k && freq.size()==k){
                maxsum = max(maxsum, currsum);
            }
            r++;
        }
        return maxsum;
    }
};
