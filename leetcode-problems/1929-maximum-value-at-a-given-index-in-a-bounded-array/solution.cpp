class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long long low = 1, high = maxSum, res = 1;
        auto getsum = [](long long v, long long cnt)->long long{
            if(v>=cnt){
                return (v + v-cnt+1)* cnt/2;
            }else{
                return((v*(v+1))/2 +(cnt - v));
            }
        };
        while(low<=high){
            long long mid = low + (high -low )/2;
            long long tot = getsum(mid,index+1) + getsum(mid, n-index) - mid;
            if(tot<=maxSum){
                res = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return (int)res;
    }
};
