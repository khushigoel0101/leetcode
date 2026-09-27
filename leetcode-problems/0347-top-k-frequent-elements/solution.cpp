class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //BUCKET SORT -
        //1.store the frequencies in a map
        unordered_map<int,int>mpp;
        for(int i =0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        //2. create buckets where index = frequency
        vector<vector<int>>bucket(nums.size()+1);
        for(auto [num, freq]: mpp){
            bucket[freq].push_back(num);
        }

        //3. get the top k elements by right to left
        vector<int>result;
        for(int i = bucket.size()-1; i>=0; i--){
            for(int num: bucket[i]){
                result.push_back(num);
            }if(result.size()==k){
                return result;
            }
        }
        return result;
    }
};
