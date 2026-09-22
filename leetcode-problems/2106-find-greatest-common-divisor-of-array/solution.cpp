class Solution {
public:
    int gcd(int a, int b){
        while(b!=0){
            int temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }
    int findGCD(vector<int>& nums) {
        ranges::sort(nums);
        int a = nums[0];
        int b = nums[nums.size()-1];
        int res = gcd(a,b);
        return res;
    }
};
