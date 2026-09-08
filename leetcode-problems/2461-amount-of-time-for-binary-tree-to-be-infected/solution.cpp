/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //use bfs and create undirected graph
    void makegraph(TreeNode* root,unordered_map<int, vector<int>>& adj, int parent){
        if(root==nullptr)return;
        if(parent!=-1) adj[root->val].push_back(parent);
        if(root->left) adj[root->val].push_back(root->left->val);
        if(root->right) adj[root->val].push_back(root->right->val);
        makegraph(root->left, adj, root->val);
        makegraph(root->right, adj, root->val);
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        makegraph(root, adj, -1);

        //apply bfs from start node
        queue<int>q;
        unordered_set<int>visited;
        q.push(start);
        visited.insert(start);
        int mins = 0;
        while(!q.empty()){
            //jab level nikalna ho toh 
            int n = q.size();
            while(n--){
                int curr = q.front();
                q.pop();
                for(int v: adj[curr]){
                    if(visited.find(v)==visited.end())
                    q.push(v);
                    visited.insert(v);
                }
            }
            mins++;
        }
        return mins > 0 ? mins - 1 : 0;
    }
};
