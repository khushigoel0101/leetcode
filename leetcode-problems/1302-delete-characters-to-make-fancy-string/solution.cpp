class Solution {
public:
    string makeFancyString(string s) {
        vector<char>v;
        int c =1;
        v.push_back(s[0]);
        for(int i =1; i<s.length();i++){
            if(s[i]==s[i-1]){
                c++;
            }
            else{
                c=1;
            }
            if(c<3){
                v.push_back(s[i]);
            }
        }
        string p(v.begin(),v.end());
        return p;
    }
};
