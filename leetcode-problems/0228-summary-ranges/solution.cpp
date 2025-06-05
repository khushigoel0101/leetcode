class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> v;
        vector<int> t;

        if (nums.empty()) return v;

        t.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i] - 1) == nums[i - 1]) {
                // Consecutive: keep adding to t
                t.push_back(nums[i]);
            } else {
                // Not consecutive: finalize current range
                if (t.size() == 1) {
                    v.push_back(to_string(t[0]));
                } else {
                    v.push_back(to_string(t[0]) + "->" + to_string(t[t.size() - 1]));
                }
                t.clear();
                t.push_back(nums[i]);
            }
        }

        // Final range after loop
        if (!t.empty()) {
            if (t.size() == 1) {
                v.push_back(to_string(t[0]));
            } else {
                v.push_back(to_string(t[0]) + "->" + to_string(t[t.size() - 1]));
            }
        }

        return v;
    }
};

