class Solution {
public:
    bool possible(vector<int>& nums, int mid , int n){
         int c = 0; 
         for(int b: nums){
            c += (b-1)/mid;
            if(c>n) return false;
         }
         return true;
       
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
       int low = 1, high = *max_element(nums.begin(),nums.end());
       int res = 0;
       while(low<=high){
        int mid = low + (high-low)/2;
        if(possible(nums,mid, maxOperations)){
            res = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
       } 
       return res;
    }
};
