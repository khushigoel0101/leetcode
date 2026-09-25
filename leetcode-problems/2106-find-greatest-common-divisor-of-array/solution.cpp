class Solution {
public:
    int gcd(int a, int b){
        while(b!=0){
            int temp = b;//save
            b = a%b;//remainder
            a = temp;//shift
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
