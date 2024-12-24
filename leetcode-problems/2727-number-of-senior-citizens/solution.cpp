class Solution {
public:
    int countSeniors(vector<string>& details) {
       
        int c =0;
        for(int i =0; i<details.size(); i++){
             vector<char>v;
            for(int j = 11; j<13; j++){
                v.push_back(details[i][j]);
            }
            string s = string(v.begin(),v.end());
            int n = std::stoi(s);
            if(n>60){
                c++;
            }
        }
        return c;
    }
};
