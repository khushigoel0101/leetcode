class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mpp;
        unordered_set<int> children;

        for (const auto& desc : descriptions) {
            int parent = desc[0];
            int child = desc[1];
            int isLeft = desc[2];

            if (mpp.find(parent) == mpp.end()) {
                mpp[parent] = new TreeNode(parent);
            }
            TreeNode* parentNode = mpp[parent];

            if (mpp.find(child) == mpp.end()) {
                mpp[child] = new TreeNode(child);
            }
            TreeNode* childNode = mpp[child];

            if (isLeft) {
                parentNode->left = childNode;
            } else {
                parentNode->right = childNode;
            }

            children.insert(child);
        }

        for (const auto& pair : mpp) {
            int value = pair.first;

            if (children.find(value) == children.end()) {
                return pair.second;
            }
        }

        return nullptr;
    }
};
