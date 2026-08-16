class Solution {
public:
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int ans = 0;
        int low = 1, high = 1e7;
        auto reachoff = [&](int mid)->bool{
          double tot_time = 0;
          for(int i = 0; i<dist.size()-1; i++){
            tot_time += ceil((double)dist[i]/mid);
          }
            tot_time += (double)dist[dist.size()-1]/mid;
          if(tot_time<=hour)return true;
          else return false;
        };

        while(low<=high){
            int mid = low + (high - low)/2;
            if(reachoff(mid)){
            ans = mid;
            high = mid-1;
            }else{
                low = mid + 1;
            }
        }
        return ans==0?-1:ans;
    }
};
