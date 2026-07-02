class Solution {
public:

    long long hoursneed(vector<int>&piles, int k){
        long long hours = 0;
        for(int p : piles){
            hours += (p + k - 1)/k;
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(),piles.end());
        while(low<high){
            int mid = low + (high-low)/2;
            if(hoursneed(piles,mid)<=h){
                high = mid;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};
