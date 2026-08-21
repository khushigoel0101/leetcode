class Solution {
public:
    bool isposs(vector<int>& ranks,long long mid, long long cars){
        long long cnt = 0;
        for(long long i =0; i<ranks.size(); i++){
          cnt += sqrt(mid / ranks[i]);
        }
        if(cnt>=cars){
            return true;
        }else return false;
    }
    long long repairCars(vector<int>& ranks, long long cars) {
        long long low = 1;
        sort(ranks.begin(), ranks.end());
        long long res = 0;
        long long high = ranks[0] * cars * cars;
        while(low<=high){
            long long mid = low + (high - low)/2;
            if(isposs(ranks, mid, cars)){
                res = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return res;
    }
};
