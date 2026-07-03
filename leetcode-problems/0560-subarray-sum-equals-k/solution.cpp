class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        unordered_map<int,int>mpp;
        mpp[0]=1; int prefixSum = 0;
        for(int num: nums){
            prefixSum += num;       
            if(mpp.find(prefixSum-k)!=mpp.end()){
                count+= mpp[prefixSum-k];
            }
            mpp[prefixSum]++;
        }
        return count;
    }
};
