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
/*solve normaaly using bfs get maxel at each level 
for dfs: compare elements at each depth maxel at each index of res*/
   vector<int>res;
   void dfs(TreeNode* root, int d){
        if(root==NULL)return;
        if(res.size()==d){ //if visiting the depth for the first time
            res.push_back(root->val);
        }else{
            res[d] = max(res[d], root->val);
        }
        dfs(root->left,d+1);
        dfs(root->right, d+1);
   }
    vector<int> largestValues(TreeNode* root) {
        dfs(root,0);
        return res;
    }
};
