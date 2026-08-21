class Solution {
public:
    bool possible(vector<int>& nums, int mid, int k){
        int cnt = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]<=mid){
                cnt++;
                i++;
            }else{
                continue;
            }
        }
        if(cnt>=k) return true;
        else{
            return false;
        }
    }
    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high =  *max_element(nums.begin(), nums.end());
        int res = 0;
        while(low<=high){
            int mid = low + (high -low)/2;
            if(possible(nums, mid, k)){
                res = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return res;
    }
};
