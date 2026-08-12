class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(x==parent[x])
        return parent[x];

        return x = find(parent[x]);
    }
    void Union(int x,int y){
        int x_parent = find(x);
        int y_parent = find(y);
        if(x_parent == y_parent){
         return;
        } 
        if(rank[y_parent]>rank[x_parent]){
            parent[x_parent] = y_parent;
        } else if(rank[x_parent]>rank[y_parent]){
            parent[y_parent] = x_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(n-1>m)return -1;
        
        parent.resize(n);
        rank.resize(n,0);
        for(int i = 0; i<n; i++){
            parent[i] = i;
            rank[i] = i;
        }
        int comp = n;
        for(auto it: connections){
            if(find(it[0])!= find(it[1])){
                Union(it[0], it[1]);
                comp--;
            }
        }

        return comp-1;
    }
};
