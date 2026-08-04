class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if (nums.empty()) return {};

        int lo = *min_element(nums.begin(), nums.end());
        int hi = *max_element(nums.begin(), nums.end());

        unordered_set<int> present(nums.begin(), nums.end());

        vector<int> res;
        for (int i = lo; i <= hi; i++) {
            if (!present.count(i)) {
                res.push_back(i);
            }
        }
        return res;
    }
};
