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
     int max_sum ;

     int solve(TreeNode* root){
        if(root == NULL) return 0;

        int l = solve(root->left);
        int r = solve (root->right);

        int neeche_hi_accha = l + r + root->val;
        int ek_accha = max(l,r) + root->val;
        int srif_root_accha = root->val;

        max_sum = max({ max_sum, neeche_hi_accha, ek_accha, srif_root_accha });

        return max (ek_accha, srif_root_accha);
    }
    int maxPathSum(TreeNode* root) {
        max_sum = INT_MIN;

        solve(root);

        return max_sum;

    }
};
