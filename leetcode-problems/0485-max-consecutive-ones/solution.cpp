class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c=0,maxx = 0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]==1){
                c++;
                maxx=max(c,maxx);
            }
            else{
                c=0;
            }
        }
        return maxx;
    }
};
