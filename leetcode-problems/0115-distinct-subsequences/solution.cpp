class Solution {
public:
    int numDistinct(string s, string t) {
        int a = s.length();
        int b = t.length();

        vector<vector<long long>> dp(a+1, vector<long long>(b+1, 0));

        for(int i = 0; i <= a; i++) dp[i][0] = 1;  

        for(int i = 1; i <= a; i++){
            for(int j = 1; j <= b; j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = min((long long)INT_MAX, dp[i-1][j-1] + dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];                 
            }
        }

        return dp[a][b];
    }
};
