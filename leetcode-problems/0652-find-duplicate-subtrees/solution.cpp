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
    string getstring(TreeNode* root, unordered_map<string, int>& mpp, vector<TreeNode*>& res){
        if(root==NULL) return "N";

        string s = to_string(root->val) +","+ getstring(root->left, mpp, res) +","+  getstring(root->right, mpp, res);

        if(mpp[s]==1){
            res.push_back(root);
        }
        mpp[s]++;

        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        
        unordered_map<string, int>mpp;

        getstring(root, mpp, res);

        return res;
    }
};
