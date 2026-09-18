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
    int maxDiameter = 0;
    //left se bilkul neeche + right se bilkul neeche
    int depth(TreeNode* node) {
        if (node == nullptr) return 0;

        int leftDepth = depth(node->left);
        int rightDepth = depth(node->right);

        // Update the maximum diameter
        maxDiameter = max(maxDiameter, leftDepth + rightDepth);

        // Return the height of the current node
        return 1 + max(leftDepth, rightDepth);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return maxDiameter;
    }
};
