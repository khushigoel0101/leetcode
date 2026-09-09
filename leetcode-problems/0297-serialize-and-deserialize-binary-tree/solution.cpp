/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)
            return "";
        string res = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr == nullptr)
                res += "null,";
            else {
                res += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        if (!res.empty()) {
            res.pop_back();
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;
            //used for discarding "," and getting the value
        stringstream ss(data);
        string item;
        getline(ss, item, ',');
        if (item == "null")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(item));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            //1.process left child
            if (getline(ss, item, ',')) {
                if (item != "null") {
                    curr->left = new TreeNode(std::stoi(item));
                    q.push(curr->left);
                }
            }

            // 2. process right child
            if (getline(ss, item, ',')) {
                if (item != "null") {
                    curr->right = new TreeNode(std::stoi(item));
                    q.push(curr->right);
                }
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
