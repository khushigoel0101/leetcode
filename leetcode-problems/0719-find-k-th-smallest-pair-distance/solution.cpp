class Solution {
public:
    int count (vector<int>& nums, int mid){
        int cnt = 0, j = 0;
        for(int i = 0; i<nums.size(); i++){
            while (j < nums.size() && nums[j] - nums[i] <= mid) {
              j++;
            }
            cnt += j - i - 1;
        }
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int low = 0, high = nums[n-1] - nums[0];
        while(low<high){
            int mid = low + (high - low)/2;
            if(count(nums,mid)>=k){
                high = mid;
            }else{
                low = mid +1;
            }
        }
        return low;
    }
};
