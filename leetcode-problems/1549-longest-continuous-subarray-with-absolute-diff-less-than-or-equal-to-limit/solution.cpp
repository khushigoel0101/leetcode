class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int l = 0;
        deque<int>maxq;
        deque<int>minq;
        int r = l;
        int res = 0;
        while(r<n){
          while(!maxq.empty() && nums[maxq.back()]<nums[r]){
            maxq.pop_back();
          }
          maxq.push_back(r);
          while(!minq.empty() && nums[minq.back()]>nums[r]){
            minq.pop_back();
          }
          minq.push_back(r);
          while(nums[maxq.front()] - nums[minq.front()]>limit){
            l++;
            if(maxq.front()<l)maxq.pop_front();
            if(minq.front()<l)minq.pop_front();
          }

          res = max(res,r-l+1);

          r++;


        }
        return res;
    }
};
