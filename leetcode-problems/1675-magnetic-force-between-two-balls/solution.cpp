class Solution {
public:
    bool check(vector<int>& position,int force, int m){
       int balls = 1;
       int pos = position[0];
       for(int i = 1; i<position.size(); i++){
         if(abs(position[i]-pos) >= force){
              balls ++;
             pos = position[i];
           }
           if(balls==m) break;
       }
       if(balls<m){
        return false;
       }else{
        return true;
       }
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1, high = (position.back() - position.front());
        int res = 0;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(check(position,mid, m)){
               res = mid;
               low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return res;
    }
};
