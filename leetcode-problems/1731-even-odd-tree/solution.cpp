class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (!root) return true;
        
        queue<TreeNode*> q;
        q.push(root);
        int idx = 0;
        
        while (!q.empty()) {
            int n = q.size();
            
            if (idx % 2 == 0) {
                int el = INT_MIN; 
                while (n--) {
                    TreeNode* curr = q.front();
                    q.pop();
                    
                    if (curr->val % 2 == 0 || curr->val <= el) return false;
                    else el = curr->val;
                    
                    if (curr->left != nullptr) q.push(curr->left);
                    if (curr->right != nullptr) q.push(curr->right);
                }
            } else {
                int el = INT_MAX; 
                while (n--) {
                    TreeNode* curr = q.front();
                    q.pop();
                    
                    if (curr->val % 2 != 0 || curr->val >= el) return false;
                    else el = curr->val;
                    
                    if (curr->left != nullptr) q.push(curr->left);
                    if (curr->right != nullptr) q.push(curr->right);
                }
            }
            idx++;
        }
        return true;
    }
};
