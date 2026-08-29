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
    void fill(TreeNode* root, vector<int>&t){
        if(root==NULL) return;
        
        if(root->left == NULL && root->right==NULL){
            t.push_back(root->val);
        }

        fill(root->left,t);
        fill(root->right, t);
        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>t1;
        vector<int>t2;
        fill(root1, t1);
        fill(root2, t2);
        return t1 == t2;
    }
};
