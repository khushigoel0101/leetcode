class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>result;
        bool inserted = false;
       for(auto iv: intervals){
        if(iv[1]<newInterval[0]){
           result.push_back(iv);
        }else if(iv[0]>newInterval[1]){
            if(!inserted){
             result.push_back(newInterval);
             inserted = true;
            }
             result.push_back(iv);
        }else{
            newInterval[0] = (min(iv[0],newInterval[0]));
            newInterval[1] = (max(iv[1],newInterval[1]));
        }
       }
       if(!inserted)
       result.push_back(newInterval);
       return result;
    }
};
