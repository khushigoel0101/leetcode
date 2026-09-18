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
    TreeNode* lca(TreeNode* root, int src, int dest){
        if(!root) return nullptr;
        if(root->val == src || root->val == dest){
            return root;
        }
        TreeNode* l = lca(root->left, src, dest);
        TreeNode* r = lca(root->right, src, dest);

        if(l&&r) return root;

        return l? l:r;
    }

    bool findpath(TreeNode* start, int node, string& res){
        if(!start) return false ;
        if(start->val == node) return true;
        res += "L";
        if(findpath(start->left, node, res) )return true;
        res.pop_back();
        res += "R";
        if(findpath(start->right,  node, res))return true;
        res.pop_back();
        return false;
    }
//find LCA , then source to lca path and lca to destination path , source to lca change with U
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = lca(root, startValue, destValue);
        string lcatosrc = "";
        string lcatodest = "";
        findpath(LCA, startValue, lcatosrc);
        findpath(LCA, destValue, lcatodest);
        string res = "";
        int cnt = lcatosrc.length();
        while(cnt--){
            res+="U";
        }
        res += lcatodest;
        return res;
    }
};
