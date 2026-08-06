class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& recstack) {
        visited[u] = true;
        recstack[u] = true;

        for (int v : adj[u]) {
            if (!visited[v]) {
                if (!dfs(adj, v, visited, recstack)) {
                    return false; 
                }
            } else if (recstack[v]) {
                return false; 
            }
        }

        recstack[u] = false; 
        return true; 
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for (auto& it : prerequisites) {
            int a = it[0];
            int b = it[1];
            adj[b].push_back(a);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> recstack(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!dfs(adj, i, visited, recstack)) {
                    return false;
                }
            }
        }
        return true;
    }
};
