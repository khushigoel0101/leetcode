class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.length(), n2= num2.length();
        int i = n1-1, j = n2-1;
        int carry = 0; 
        string res = "";
        while(i>=0 || j>=0 || carry>0){
            int digit1 = (i>=0) ? num1[i]-'0' : 0;
            int digit2 = (j>=0) ? num2[j]-'0' : 0;
            int tot = digit1 + digit2 + carry;
            carry = tot/10;
        
            res.push_back((tot%10)+'0');
            i--; j--;
        }
         reverse(res.begin(), res.end());
         return res;
    }
   
};
