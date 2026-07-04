class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for(int j =0; j<nums.size(); j++){
            if(nums[j]!=0){
               swap(nums[i], nums[j]);
               i++;
            }
        }
    }
};

//j krta hai kaam, wo non zero element utha kr ith position pr rakhta hai aur i bs non zero positions dhundta hai .
