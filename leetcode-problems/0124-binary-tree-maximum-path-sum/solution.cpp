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
    int maxSum;

    int dfs(TreeNode* node) {
        if (!node) return 0;

        int leftGain = max(0, dfs(node->left));  
        int rightGain = max(0, dfs(node->right));
        int pathSum = node->val + leftGain + rightGain;

        maxSum = max(maxSum, pathSum);
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        dfs(root);
        return maxSum;
    }
};

