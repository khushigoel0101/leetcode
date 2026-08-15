class Solution {
public:
    bool isposs(vector<int>&piles, int mid, int h){
        long long hr = 0; 
        for(int p : piles){
            hr += p/mid;
            if(p%mid!=0){
                hr++;
            }
        }
        return hr<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1; int high = *max_element(begin(piles), end(piles));
        while(low<=high){
            int mid = low + (high - low)/2;
            if(isposs(piles, mid, h)){
                high = mid -1;
            }else{
                low = mid +1;
            }
        }
        return low;
    }
};
