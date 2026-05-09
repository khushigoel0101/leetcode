class Solution {
public:
    int minDistance(string word1, string word2) {
        int a = word1.length();
        int b = word2.length();

        vector<vector<int>>dp(a+1, vector<int>(b+1, 0));
        for(int i =1; i<=a; i++){
            for(int j = 1; j<=b; j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int dis = dp[a][b];
        return (a - dis) + (b - dis);

    }
};
