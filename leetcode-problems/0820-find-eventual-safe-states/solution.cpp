class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revadj(n);
        vector<int> indegree(n,0);

        for(int u = 0; u<n; u++){
            for(int v: graph[u]){
                revadj[v].push_back(u);
            }
            indegree[u] = graph[u].size();
        }

        queue<int>q;
        for(int i = 0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<bool>safe(n,false);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe[node] = 1;

            for(int v: revadj[node]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        vector<int>res;
        for(int i = 0; i<n; i++){
            if(safe[i]){
                res.push_back(i);
            }
        }
        return res;
    }
};
