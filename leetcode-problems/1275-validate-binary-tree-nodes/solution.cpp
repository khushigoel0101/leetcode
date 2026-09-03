class Solution {
public:
/* 3 THINGS TO CHECK - 
 1. every child should have only one parent - child to parent map
 2. only one root - only one element missing from map
 3. connected (only one component) - create adj list , travrse and keep nodes count*/
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int, vector<int>>adj;
        unordered_map<int,int>child_to_parent;

        for(int i = 0; i<n; i++){
            int node = i;
            int leftc = leftChild[i];
            int rightc = rightChild[i];

            if(leftc!=-1){
                adj[i].push_back(leftc);
                if(child_to_parent.find(leftc)!=child_to_parent.end())
                return false;
                child_to_parent[leftc] = i;
            }
             if(rightc!=-1){
                adj[i].push_back(rightc);
                if(child_to_parent.find(rightc)!=child_to_parent.end())
                return false;
                child_to_parent[rightc] = i;
            }
        }
        int root = -1;
        for(int i = 0; i<n; i++){
            if(child_to_parent.find(i)==child_to_parent.end()){
                if(root!=-1){
                    return false;
                }else{
                    root=i;
                }
            }
        }
        if(root==-1) return false;
        int cnt = 0;
        queue<int>q;
        vector<bool>visited(n,false);
        q.push(root);
        cnt = 1;
        visited[root] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int &v: adj[node]){
               if(!visited[v]){
                visited[v] = true;
                cnt++;
                q.push(v);
               }
            }
        }
        return cnt == n;
    }
};
