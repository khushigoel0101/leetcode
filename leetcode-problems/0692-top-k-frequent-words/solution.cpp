class Solution {
public:
    struct compare{
        bool operator()(const pair<int, string>&a, pair<int, string>&b){
          if(a.first == b.first) return a.second<b.second;
          return a.first>b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
       vector<string>res;
        priority_queue<pair<int, string>, vector<pair<int,string>>, compare>min_heap;
        unordered_map<string,int>mpp;
        for(string s: words){
            mpp[s]++;
        }
        for(auto pair: mpp){
            min_heap.push({pair.second, pair.first});
            if(min_heap.size()>k){
                min_heap.pop();
            }
        }
        while(!min_heap.empty()){
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
         reverse(res.begin(),res.end());
         return res;
    }
};
/*
["i","love","leetcode","i","love","coding"]
k = 2

*/
