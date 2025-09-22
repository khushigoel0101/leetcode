class Solution {
public:
    
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> f;
        for(int num: nums){
            f[num]++;
        }

        int m = 0;
        for (auto &p : f) {
            m = max(m, p.second);
        }

        int ans = 0;
        for (auto &p : f) {
            if (p.second == m) {
                ans += p.second;
            }
        }
        return ans;
        
    }
};
