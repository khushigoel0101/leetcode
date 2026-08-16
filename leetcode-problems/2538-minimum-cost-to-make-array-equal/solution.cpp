class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        auto getcost = [&](int mid)-> long long {
            long long ans = 0;
           for(int i = 0;i<nums.size(); i++){
            ans+=abs(nums[i]-mid)*1LL*cost[i]*1LL;
           }
           return ans;
        };
        long long mcost = LLONG_MAX;
        while(low<=high){
            int mid = low +(high-low)/2;
            long long cost_mid = getcost(mid);
            long long cost_next =(mid==high)?LLONG_MAX:getcost(mid+1);
            if(cost_mid<=cost_next){
                mcost = min(mcost,cost_mid);
                high = mid - 1;
            }else{
                low = mid+1;
            }
        }
        return mcost;
    }
};
