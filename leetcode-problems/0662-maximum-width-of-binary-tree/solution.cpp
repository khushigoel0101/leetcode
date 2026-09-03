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
        queue<pair<TreeNode* , long long>>q;
        q.push({root,0});
        long long maxw = 0;
        while(!q.empty()){
            unsigned long long min_idx = q.front().second; // First element's index in current level
            long long l = q.front().second;
            long long r = q.back().second;
            maxw = max(maxw, r-l+1);
            int n = q.size();
            while(n--){
                TreeNode* curr = q.front().first;
                // Normalize index relative to the level's starting index
                unsigned long long idx = q.front().second - min_idx;
                q.pop();

                if(curr->left)q.push({curr->left, 2*idx+1});
                if(curr->right)q.push({curr->right, 2*idx + 2});
            }
        }
        return maxw;
    }
};
