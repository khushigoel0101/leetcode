class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += arr[i];
        }
        if(sum%3!=0)return false;
        int curr = 0;
        int cnt = 0;
        for(int i = 0; i<n; i++){
            curr += arr[i];
            if(curr==sum/3){
                curr = 0;
                cnt++;
            }
            if(cnt==2 && i<arr.size()-1){
                return true;
            }
        }
        return false;
    }
};
