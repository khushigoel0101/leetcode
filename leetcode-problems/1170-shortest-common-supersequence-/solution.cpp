class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int a = str1.length();
        int b = str2.length();

        vector<vector<int>>dp(a+1, vector<int>(b+1,0));
        for(int i = 1; i<=a; i++){
            for(int j = 1; j<=b; j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        string s = "";
        int i = a, j = b;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                s = s+str1[i-1];
                i--;
                j--;
            }else if(dp[i-1][j] > dp[i][j-1]){
               s = s+ str1[i-1];
               i--;
            }else{
                s = s+ str2[j-1];
                j--;
            }

        }
        while(i > 0) { s += str1[i-1]; i--; } 
        while(j > 0) { s += str2[j-1]; j--; } 
        reverse(s.begin(), s.end());
        return s;
    }
};
