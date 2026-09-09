/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != nullptr) {
            // If a left child exists, we need to rewire it
            if (curr->left != nullptr) {
                // Find the rightmost node in the left subtree
                TreeNode* prev = curr->left;
                while (prev->right != nullptr) {
                    prev = prev->right;
                }

                // Connect the original right subtree to the right of 'prev'
                prev->right = curr->right;

                // Move the entire left subtree to the right side
                curr->right = curr->left;
                curr->left = nullptr; // Clear the left pointer
            }

            // Move down the flattened right pathway
            curr = curr->right;
        }
    }
};
