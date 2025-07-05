class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();
      unordered_map<int,int>z;
        for(int i =0; i<n; i++){
           z[x[i]]=max(z[x[i]],y[i]);
        }

        vector<int>t;
    for (auto& [key, val] : z) {
        t.push_back(val);
    }
    if (t.size() < 3) return -1;

    sort(t.rbegin(), t.rend());
    return t[0] + t[1] + t[2];
    }
};
