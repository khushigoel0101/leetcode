class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>v;
        for(int i =0; i<n; i++){
           long long sum = 0;
           for(int j =i;j<n;j++){
            sum = sum + nums[j];
            v.push_back(sum);
           }
        }
        sort(v.begin(),v.end());
        long long result = std::accumulate(v.begin() + left - 1, v.begin() + right, 0LL);
        return  result % 1000000007;
    }
};
