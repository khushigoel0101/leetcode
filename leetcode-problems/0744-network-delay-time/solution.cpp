class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);

        for(auto vec: times){
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            adj[u].push_back({v,w});
        }

        vector<int>dist(n+1,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        dist[k] = 0;
        pq.push({0,k});

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(dis>dist[node])continue;
            for(auto it: adj[node]){
                int adjn = it.first;
                int wt = it.second;

                if(dis+wt<dist[adjn]){
                    dist[adjn] = dis+wt;
                    pq.push({dis+wt, adjn});
                }
            }
        }
        int mx = INT_MIN;
        for(int i = 1;i<=n; i++){
            if (dist[i] == INT_MAX) return -1;
            mx= max(dist[i],mx);
        }
        return mx;
    }
};
