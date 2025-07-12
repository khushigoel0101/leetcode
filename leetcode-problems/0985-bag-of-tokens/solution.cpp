class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(),tokens.end());
        int s = 0;
        int i = 0, j =n-1;
        int mx = 0;
        while(i<=j){
            if(power>=tokens[i]){
                power= power-tokens[i];
                s += 1;
                i++;
                mx = max(mx,s);
            }else if(s>=1){
                power=power+tokens[j];
                s-= 1;
                j--;
            }else{
                return mx;
            }
        }
         return mx;
    }
};
