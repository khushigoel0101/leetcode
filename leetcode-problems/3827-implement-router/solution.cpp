#include <bits/stdc++.h>
using namespace std;

class Router {
public:
    int limit = 0;
    set<vector<int>> packets;
    unordered_map<int, int> removedPacketsFromDestination;
    unordered_map<int, vector<int>> pD;
    queue<vector<int>> q;

    Router(int memoryLimit) {
        limit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if(packets.find({source, destination, timestamp}) != packets.end()) {
            return false;
        }

        // If memory is full, remove oldest
        if(q.size() == limit) {
            vector<int> p = q.front();
            packets.erase(p);
            removedPacketsFromDestination[p[1]]++;
            q.pop();
        }

        // Push into queue
        q.push({source, destination, timestamp});
        packets.insert({source, destination, timestamp});

        // Insert timestamp into sorted position
        auto &vec = pD[destination];
        auto it = lower_bound(vec.begin(), vec.end(), timestamp);
        vec.insert(it, timestamp);

        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()) return {};
        vector<int> p = q.front();
        q.pop();
        packets.erase(p);
        removedPacketsFromDestination[p[1]]++;
        return p;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(pD.find(destination) == pD.end()) return 0;

        int removed = removedPacketsFromDestination[destination];
        auto &vec = pD[destination];

        if(removed >= (int)vec.size()) return 0;

        auto it1 = lower_bound(vec.begin() + removed, vec.end(), startTime);
        auto it2 = upper_bound(vec.begin() + removed, vec.end(), endTime);

        return int(it2 - it1);
    }
};

