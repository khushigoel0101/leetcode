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
    int goodNodes(TreeNode* root) {
        if(!root)return 0;
       return count( root, root->val);
    }
    int count(TreeNode* node, int maxVal){
        if(!node) return 0;

        int good = 0;
        if(node->val>=maxVal){
            good=1;
        }
        maxVal = max(node->val,maxVal);

        good+=count(node->left,maxVal);
        good+=count(node->right,maxVal);
        return good;

    }
};
