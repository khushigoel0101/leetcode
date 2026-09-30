class RandomizedSet {
public:
    vector<int>p;
    unordered_map<int,int>mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        p.push_back(val);
        mp[val] = p.size()-1 ;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()){
            return false;
        }
        int idx = mp[val];
        int last = p.back();
        p[idx] = last;
        mp[last] = idx;
        p.back() = val;
        p.pop_back();
        mp.erase(val);
        return true;

    }
    
    int getRandom() {
        int n = p.size();
        int rindex = rand()%n;
        return p[rindex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
