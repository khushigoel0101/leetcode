class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> index;
        for (int i = 0; i < nums.size(); i++) {
            index.push_back({nums[i], i});
        }
        
        sort(index.begin(), index.end());

        int l = 0, r = index.size() - 1;
        while (l < r) {
            int sum = index[l].first + index[r].first;
            
            if (sum == target) {
                return {index[l].second, index[r].second};
            } else if (sum < target) {
                l++;
            } else {
                r--;
            }
        }
        
        return {};
    }
};
