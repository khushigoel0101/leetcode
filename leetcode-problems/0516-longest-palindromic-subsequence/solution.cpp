class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int a = s.length();
        string rev = s;
        reverse(rev.begin(), rev.end());

        vector<vector<int>> dp(a+1, vector<int>(a+1, 0));

        for(int i = 1; i <= a; i++){
            for(int j = 1; j <= a; j++){
                if(s[i-1] == rev[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[a][a];
    }
};
