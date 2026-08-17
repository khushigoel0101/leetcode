class Solution {
public:
    bool possible(vector<int>& nums, int p, int mid){
        int c = 0;
     for(int i =0; i<nums.size()-1; i++){
        if(nums[i + 1] - nums[i] <= mid){
            c++;
            i++;
        }
     }
     return c>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int low = 0,  high = *max_element(nums.begin(),nums.end()) - *min_element(nums.begin(),nums.end());
        int res = 0;
        while(low<=high){
            int mid = low + (high-low + 1)/2;
            if(possible(nums, p ,mid)){
                res = mid;
                high = mid-1;
            }else{
                low = mid + 1;
            }
        }
        return res;
    }
};
