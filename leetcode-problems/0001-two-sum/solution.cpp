class Solution {
public:
   void f(int i , int target , vector <int>&nums ,vector <int>&ds )
   {
        if(i>=nums.size()-1)
        {
            return;
        }
        for (int j = i+1; j<nums.size();j++){
        if ( nums[i] + nums[j] == target ){
        ds.push_back(i);    
        ds.push_back(j);
        return;
        }
        }
        f(i+1,target,nums,ds);
        
   }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ds;
        f(0, target , nums , ds);
        return ds;
        
    }
};
