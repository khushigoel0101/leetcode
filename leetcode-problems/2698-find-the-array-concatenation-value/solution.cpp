class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long total = 0;
        int i = 0, j = nums.size()-1;
        while(i<j){
            string s = to_string(nums[i]);
            string g = to_string(nums[j]);
           string conc = s+g;
            i++;
            j--;
            total = total + stoi(conc);
        }
        if(i==j){
            total = total + nums[i];
        }
        return total;

    }
};
