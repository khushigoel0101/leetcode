class RandomizedSet {
public:
//for removal - first find the element in the map , swap it with the last element in the vector, then pop from the vector and erase from the map
    vector<int>vec;
    unordered_map<int,int>mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        vec.push_back(val);
        mp[val] = vec.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end())
        return false;
        int idx = mp[val];
        int lastel = vec.back();
        vec.back() = val;
        vec[idx] = lastel;
        mp[lastel] = idx;
        vec.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int n = vec.size();
        int rindex = rand()%n;
        return vec[rindex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
