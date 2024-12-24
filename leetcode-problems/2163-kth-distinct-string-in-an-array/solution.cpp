class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>mpp;
         for (const string& s : arr) {
            mpp[s]++;
        }
        int c = 0;
        for(const string& s: arr){
            if(mpp[s]==1){
                c++;
            }
            if(c==k){
                return s;
            }
        }
       return "";
    }
};
