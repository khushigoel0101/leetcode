class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        string half = s.substr(0,n/2);
        sort(half.begin(), half.end());
        string temp = half;
        if(n%2!=0){
            temp += s[n/2]; 
        }
        string r = half;
        reverse (r.begin(), r.end());
        temp += r;
        return temp;
    }
};
