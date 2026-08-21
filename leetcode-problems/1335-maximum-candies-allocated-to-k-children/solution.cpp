class Solution {
public:
    bool possible(vector<int>& candies,int mid, long long k){
        long long cnt = 0;
        for(int i: candies){
            cnt += i/mid;
        }
        if(cnt>=k){
            return true;
        }else{
            return false;
        }
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1, high = *max_element(candies.begin(),candies.end());
        int res = 0;
        while(low<=high){
            int mid = low + (high -low)/2;
            if(possible(candies, mid, k)){
                res = mid;
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        return res;
    }
};
