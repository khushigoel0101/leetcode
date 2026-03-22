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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
        return 0;

        int maxW = 0;

        queue<pair<TreeNode*, long long>> q;

        q.push({root, 0});

        while(!q.empty()){
            int size = q.size();
            int mi = q.front().second;

            int f =0;
            int l = 0;

            for(int i =0; i<size; i++){
                long long in = q.front().second - mi;
                TreeNode* node = q.front().first;

                q.pop();

                if(i==0)
                f = in;

                if(i==size-1)
                l = in;

                if (node->left)
                    q.push({node->left, 2 * in + 1});

                if (node->right)
                    q.push({node->right, 2 * in + 2});
            }

            maxW = max(maxW, l-f+1);
        }
        return maxW;
    }
};
