class FindSumPairs {
public:
    unordered_map<int,int>mp;
    vector<int>arr1,arr2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1, arr2=nums2;
        for(auto num: nums2){
           mp[num]++;
        }
    }
    
    void add(int index, int val) {
        mp[arr2[index]]--;
        mp[arr2[index]+val]++;
        arr2[index] += val;
    }
    
    int count(int tot) {
        int cnt = 0;
        for(int i =0; i<arr1.size(); i++){
            if(mp.find(tot-arr1[i])!= mp.end()){
                cnt += mp[tot-arr1[i]] ;
            }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
