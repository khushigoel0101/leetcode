class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int>db(nums.begin(),nums.end());
        for(int i = 0; i<nums.size(); i++){
            db.push_back(nums[i]);
        }
        int cnt_one = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==1)
            cnt_one++;
        }
        int l = 0, r= 0, max_sub=0;int cnt=0;
        while(r<db.size()){
            if(db[r]==1){
                cnt++;
            }
            if(r-l+1>cnt_one){
                if(db[l]==1){
                    cnt--;
                }
                l++;
            }
            if(r-l+1 == cnt_one){
                max_sub = max(max_sub, cnt);
            }
            r++;
        }
        return cnt_one - max_sub;
    }
};
