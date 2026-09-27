class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //same logic as move zeros to end
        int n = nums.size();
        int l = 0;
        for(int i = 0; i<n; i++){
            if(nums[i]!=val){
                nums[l] = nums[i];
                l++;
            }
        }
        return l;
    }
};
