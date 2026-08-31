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
    long long sum = 0 ;
    long long maxp = 0;
    int tot(TreeNode* root){
        if(root==NULL) return 0;

        int l = tot(root->left);
        int r = tot(root->right);

        int curr =  root->val + l + r;
        maxp = max(maxp,(long long)curr * (sum - curr));

        return curr;
    }
    int maxProduct(TreeNode* root) {
       if(root==NULL) return 0;
       sum =  tot(root);
       maxp = 0;

       tot(root);

       return maxp % 1000000007;
        
    }
};
