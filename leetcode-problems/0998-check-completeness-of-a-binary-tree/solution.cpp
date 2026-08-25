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
    int countNodes(TreeNode* root){
        if(root==NULL) return 0;

        return 1+countNodes(root->left) + countNodes(root->right);
    }
    bool dfs(TreeNode* root, int i, int tot){
        if(root==NULL) return true;

        if(i>tot)return false;

       return dfs(root->left, 2*i, tot) && dfs(root->right, 2*i + 1, tot);

    }
    bool isCompleteTree(TreeNode* root) {
        int tot = countNodes(root);

        int i = 1;
        return dfs(root, i, tot);

    }
};
