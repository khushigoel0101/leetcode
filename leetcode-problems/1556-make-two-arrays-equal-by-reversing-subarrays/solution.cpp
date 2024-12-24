class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int f =0;
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());
        for(int i =0; i<target.size();i++){
            if(target[i]!=arr[i]){
                f = 1;
                break;
            }
        }
        if(f==0){
            return true;
        }
        else{
            return false;
        }
    }
};
