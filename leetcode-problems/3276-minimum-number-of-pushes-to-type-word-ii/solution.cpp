class Solution {
public:
    int minimumPushes(string word) {
        int p = 0;
        unordered_map<char, int> mpp;
        for (char c : word) {
            mpp[c]++;
        }
        int count =0;
        vector<int> frequencies;
        for (auto& it : mpp) {
            frequencies.push_back(it.second);
        }
        sort(frequencies.rbegin(), frequencies.rend());
        for(int i =0; i<frequencies.size();i++){
            if(i<8){
                p = p+frequencies[i];
            }
            else if(i>=8 && i<16){
                  p = p+2*(frequencies[i]);
            }
            else if(i>=16 && i<24){
                p = p+3*(frequencies[i]);
            }
            else{
                p = p+4*(frequencies[i]);
            }
        }
        return p;
    }
};
