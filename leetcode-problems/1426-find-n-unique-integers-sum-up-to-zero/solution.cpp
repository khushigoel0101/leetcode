class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>p;
        int t=1;
        int d =n/2;
        if(n%2 == 0){
          while(d){
            p.push_back(-t);
            p.push_back(abs(t));
            t++;
            d--;
          }
        }
        else{
          while(d){
            p.push_back(-t);
            p.push_back(abs(t));
            t++;
            d--;
          }
          p.push_back(0);
        }
        return(p);
    }
};
