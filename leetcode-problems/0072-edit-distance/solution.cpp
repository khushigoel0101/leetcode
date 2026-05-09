class Solution {
public:
    int minDistance(string word1, string word2) {
        int a = word1.length();
        int b = word2.length();

        vector<vector<int>> dp(a+1, vector<int>(b+1, 0));
        for(int i = 0; i <= a; i++) dp[i][0] = i;  // delete all of word1
        for(int j = 0; j <= b; j++) dp[0][j] = j;  // insert all of word2

        for(int i = 1; i <= a; i++){
            for(int j = 1; j <= b; j++){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];          // no operation needed
                else
                    dp[i][j] = 1 + min({dp[i-1][j-1], // replace
                                        dp[i-1][j],    // delete
                                        dp[i][j-1]});  // insert
            }
        }

        return dp[a][b];
    }
};
