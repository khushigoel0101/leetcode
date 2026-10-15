class Solution {
public:
   /* convert it to 2 sum problem , to find: n1+n2+n3 = 0 , we can write it as n1+n2 = -n3*/
   /* 3 steps for this prob - 1. sort bcz we have to find elements not the index
   2. duplicate handling of n1 , n2 
   3. dup handling of n3 */
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i<nums.size()-2; i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int left = i + 1, right = nums.size()-1;
            while(left<right){
                if(nums[left] + nums[right] > -nums[i]){
                    right--;
                }else if(nums[left] + nums[right] < -nums[i]){
                     left++;
                }else{
                    while( left < right && nums[left] == nums[left+1]) left++;
                    while( left < right && nums[right] == nums[right-1]) right--;
                    res.push_back({nums[left], nums[right], nums[i]});
                    left++; right--;
                }
            }
            
        }
        return res;
    }
};
