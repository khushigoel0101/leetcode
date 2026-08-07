class Solution {
public:
    bool validbfs(vector<vector<int>>& graph, vector<int>&colours, int node, int curr){
        queue<int>q;
        q.push(node);
        colours[node] = curr;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : graph[u]){
                if(colours[v]==colours[u]){
                    return false;
                }else if(colours[v]==-1){
                    colours[v] = 1-colours[u];
                    q.push(v);
                }
            }

        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>colours(n,-1);

        for(int i = 0;i<n; i++){
            if(colours[i]==-1 && !validbfs(graph, colours, i, 1))
            return false;
        }
        return true;
    }
};
