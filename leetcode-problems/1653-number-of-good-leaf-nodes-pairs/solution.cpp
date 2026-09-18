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
    void makegraph(TreeNode* root, TreeNode* prev,
                   unordered_map<TreeNode*, vector<TreeNode*>>& adj,
                   unordered_set<TreeNode*>& st) {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
            st.insert(root);
        if (prev != nullptr) {
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }
        makegraph(root->left, root, adj, st);
        makegraph(root->right, root, adj, st);
    }
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        unordered_set<TreeNode*> st;
        makegraph(root, NULL, adj, st);
        int cnt = 0;
        for (auto leaf : st) {
            queue<TreeNode*> q;
            unordered_set<TreeNode*> visited;
            q.push(leaf);
            visited.insert(leaf);

            for (int level = 0; level <= distance; level++) {
                int n = q.size();
                while (n--) {
                    TreeNode* curr = q.front();
                    q.pop();
                    if (curr != leaf && st.count(curr)) {
                        cnt++;
                    }
                    for (auto neg : adj[curr]) {
                        if (!visited.count(neg)) {
                            q.push(neg);
                            visited.insert(neg);
                        }
                    }
                }
            }
        }
        return cnt / 2;
    }
};
