class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        //cyclic sort prop
        int n = nums.size();
        int i = 0;
        while(i<n){
          int correct_idx = nums[i] - 1;
          if(nums[i]!=nums[correct_idx]){
            swap(nums[i], nums[correct_idx]);
          }else{
            i++;
          }
        }
        vector<int>res;
        for(int i = 0; i<n; i++){
            if(nums[i]!=i+1){
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
