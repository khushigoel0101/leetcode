class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            int c = 0;
            for(int j =i; j<n; j++){
                c += (nums[j] == target ? 1: -1); 
                if(c>0){
                    ans++;
                }
            }
        }
        return ans;
    }
};
