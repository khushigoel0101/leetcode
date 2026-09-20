class Solution {
public:
    // an array can have at most two such elemnts
    //use a second loop to check if the two elements actually satisfy the condition
    vector<int> majorityElement(vector<int>& nums) {
        int cn1 = 0 , cn2 = 0, el1= 0, el2 = 0;
        int n = nums.size();
        vector<int>result;
        for(int i =0; i<n; i++){
            if(cn1==0 && el2!=nums[i]){
                cn1 = 1;
                el1 = nums[i];
            }else if(cn2==0 && el1!=nums[i]){
                cn2=1;
                el2 = nums[i];
            }else if(nums[i]==el1){
                cn1++;
            }else if(nums[i]==el2){
                cn2++;
            }else{
                cn1--;
                cn2--;
            }
        }
        cn1 = 0; cn2 = 0;
        for(int i =0; i<n; i++){
            if(nums[i]==el1){
                cn1++;
            }
            if(nums[i]==el2){
                cn2++;
            }
        }
        int mini = n/3+1;
        if(cn1>=mini){
            result.push_back(el1);
        }
        if(cn2>=mini && el1!=el2){
            result.push_back(el2);
        }
        return result;
    }
};
