class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int cnt = 0;
    int currsum = 0;
    int target = threshold * k;
    int l = 0;
    
    for (int r = 0; r < arr.size(); ++r) {
        currsum += arr[r]; // Expand window by adding right element
        
        // Once the window reaches size k
        if (r - l + 1 == k) {
            if (currsum >= target) {
                cnt++;
            }
            currsum -= arr[l]; // Shrink window from the left before sliding `l`
            l++;
        }
    }
    return cnt;
}
};
