class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i<n){
            int correct_idx = nums[i] - 1;
            if(nums[i]!=nums[correct_idx]){
                swap(nums[i],nums[correct_idx]);
            }else{
                if(i!=correct_idx) break;
                i++;
            }
        }
        return nums[i];

    }
};
