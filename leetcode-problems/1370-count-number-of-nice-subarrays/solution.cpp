class Solution {
    int atMost(vector<int>&nums, int k){
        int n = nums.size();
        int ocount = 0;
        int l = 0, r = 0, count = 0;
        while(r<n){
            if(nums[r]%2!=0){
                ocount++;
            }

            while(ocount>k){
                 if(nums[l]%2!=0){
                    ocount--;
                 }
                 l++;
            }

            count += (r-l+1);
            r++;
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
        
};
