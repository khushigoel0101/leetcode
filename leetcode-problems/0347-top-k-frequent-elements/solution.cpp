class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        vector<int> t;
        for(int i =0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>m;
        for(auto it = mp.begin(); it != mp.end(); it++){
            m.push({it->second,it->first});
            if(m.size()>k){
                m.pop();
            }
        }
        while(m.size()>0){
            t.push_back(m.top().second);
            m.pop();
        }
        return t;
    }
};
