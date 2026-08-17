class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int m = flowers.size();
        int n = people.size();
        vector<int>start;
        vector<int>end;
        vector<int>res(n);
        for(int i = 0; i<m; i++){
            start.push_back(flowers[i][0]);
            end.push_back(flowers[i][1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());

        for(int i =0; i<n; i++){
            int t = people[i];
            int open = upper_bound(start.begin(), start.end(),t) - start.begin();
            int close = lower_bound(end.begin(),end.end(), t) - end.begin();
            res[i] = open - close;
        }
        return res;
    }
};
