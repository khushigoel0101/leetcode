/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
/* major challenge - going backwards in a directed tree, 
sol: make an edge from the child to parent
use a map to store the parent of each node
imp: keep a visited data structure so that we don't push a node that is already visited to our queue*/
    unordered_map<TreeNode*, TreeNode*>mpp;
    void inorder(TreeNode* root){
        if(root==NULL) return;

        if(root->left)
            mpp[root->left] = root;

        inorder(root->left);
        
        if(root->right)
            mpp[root->right] = root;
            
        inorder(root->right);
        
    }
    void BFS(TreeNode* target, int k, vector<int>&res){
        queue<TreeNode*>q;
        q.push(target);
        unordered_set<int>visited;
        visited.insert(target->val);
        while(!q.empty()){
            int n = q.size();
            if(k==0){
                break;
            }
            while(n--){
               TreeNode* node = q.front();
               q.pop();
               if(node->left && (visited.find(node->left->val)==visited.end()) ){
                  q.push(node->left);
                  visited.insert(node->left->val);
               } 
               if(node->right && (visited.find(node->right->val)==visited.end()) ){
                  q.push(node->right);
                  visited.insert(node->right->val);
               }  
               if(mpp[node] && visited.find(mpp[node]->val)==visited.end()) {
                q.push(mpp[node]);
                visited.insert(mpp[node]->val);
               }
                
            }
           k--;
        }
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       vector<int>res;
       inorder(root);
       BFS(target,k,res);
       return res;
    }
};
