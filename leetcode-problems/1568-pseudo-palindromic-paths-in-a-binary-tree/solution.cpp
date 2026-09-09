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
    int result = 0;
    void solve(TreeNode* root, vector<int>&temp){
        if(root==NULL) return;
        temp[root->val]++;
        if(root->left == NULL && root->right == NULL){
            int oddf = 0;
            for(int i = 0; i<=9; i++){
                if(temp[i]%2!=0){
                    oddf++;
                }
            }
            if(oddf<=1){
                result += 1;
            }
        }
        solve(root->left,temp);
        solve(root->right,temp);
        temp[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>count(10,0);
        solve(root,count);
        return result;
    }
};
