class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jump = 0, curend = 0, farthest = 0;
        for(int i = 0; i<n-1; i++){
            farthest = max(farthest, i + nums[i]);
            if(i == curend){
              jump++;
              curend = farthest;
            }
        }
        return jump;
    }
};
