class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        vector<int>res; 
        while(i<n){
            int crt_idx = nums[i]-1;
            if(nums[i]!=nums[crt_idx]){
                swap(nums[i],nums[crt_idx]);
            }else{
                i++;
            }
        }
        for(int i = 0; i<n; i++){
           if(nums[i]!=i+1){
             return{nums[i], i+1};
           }   
        }
        return {};
    }
};
