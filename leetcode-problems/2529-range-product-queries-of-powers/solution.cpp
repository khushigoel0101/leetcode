class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> powers;
        const int MOD = 1e9 + 7;

        for (int i = 0; i < 31; ++i) {
            if (n & (1 << i)) {
                powers.push_back(1LL << i);
            }
        }

        vector<int> productQueries;  
        for (int q = 0; q < queries.size(); ++q) {
            int left = queries[q][0];
            int right = queries[q][1];

            long long p = 1;         
            for (int i = left; i <= right; ++i) {
                p = (p * powers[i]) % MOD;
            }

            productQueries.push_back((int)p);
        }

        return productQueries;
    }
};

