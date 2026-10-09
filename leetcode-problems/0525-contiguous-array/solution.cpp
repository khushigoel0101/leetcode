class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0){
                nums[i] = -1;   //resduces the prob to subarray sum = 0
            }
        }
        unordered_map<int, int>mpp;
        mpp[0] = -1; //base case
        int maxlength = 0;
        int currsum = 0;
        for(int i = 0; i<n; i++){
            currsum += nums[i]; 
            if(mpp.find(currsum)!=mpp.end()){
                maxlength = max(maxlength,i - mpp[currsum] );
            }else{
                mpp[currsum] = i;   //storing strt index
            }
           
        }
        return maxlength;
    }
};
