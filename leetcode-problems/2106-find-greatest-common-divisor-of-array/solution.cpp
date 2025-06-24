class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a = nums[0], b = nums[nums.size() - 1];
        while(a>0 && b>0){
            if(a>b){
                a = a% b;
            }else{
                b = b% a;
            }
        }
        if(a==0)
        return b; 
        else 
        return a;
    }
};
