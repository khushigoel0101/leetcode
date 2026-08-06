class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& recstack, vector<int>& res) {
        visited[u] = true;
        recstack[u] = true;

        for (int v : adj[u]) {
            if (recstack[v]) {
                return true; 
            }
            if (!visited[v]) {
                if (dfs(adj, v, visited, recstack, res)) {
                    return true;
                }
            }
        }

        recstack[u] = false;
        res.push_back(u);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        unordered_map<int, vector<int>> adj;

        for (auto& it : prerequisites) {
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> recstack(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(adj, i, visited, recstack, res)) {
                    return {};
                }
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
