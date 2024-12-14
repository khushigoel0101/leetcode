class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        int f =0;
        for(int i =0; i<n;i++){
            for(int j =0; j<n; j++){
                  if(i!=j){
                    if(arr[i]==2*arr[j]){
                        f = 1;
                        break;
                    }
                   
                  }
                  
            }
        }
        if(f==1){
            return true;
        }
        else{
            return false;
        }
    }
};
