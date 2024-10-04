class Solution {
public:
    int minElement(vector<int>& nums) {
        for(int i =0; i<nums.size(); i++){
            int sum = 0;
             while(nums[i]!=0){
                sum = sum + nums[i]%10;
                nums[i]=nums[i]/10;
             }
             nums[i] = sum;
        }
        std::sort(nums.begin(),nums.end());
        return(nums[0]);
    }
};
