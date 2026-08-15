class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size()-1;
        int low = 0, high = n;
        int ans = 0;
        while(low<=high){
            int mid = low+(high-low)/2;
            int num = arr[mid] - (mid+1);
            if(num<k){
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        return low + k;
    }
};
