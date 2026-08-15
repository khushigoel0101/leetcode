class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(begin(potions), end(potions));
        vector<int>res;
        for(int i = 0; i<n; i++){
            int low = 0; int high = m-1;
            int c = 0;
            while(low<=high){
                int mid = low+(high-low)/2;
                if(1LL * spells[i] * potions[mid]>=success){
                    high = mid - 1;
                    c = m-mid;
                }else
                    low = mid + 1;
                
            }
            res.push_back(c);
        }
        return res;
    }
};
