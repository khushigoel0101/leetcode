class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]<0){
                neg.push_back(nums[i]);
            }else{
                pos.push_back(nums[i]);
            }
        }
        vector<int>res;
        int i=0, j = 0;
        while(i<pos.size() && j<neg.size()){
          res.push_back(pos[i]);
          res.push_back(neg[j]);
          i++; j++;
        }
        return res;
    }
};
