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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> v;
        if (root == nullptr) {
            return {};
        } else {
            q.push(root);
        }
        int i = 1;
        while(!q.empty()) {
            vector<int> l;
            int size = q.size();
            for (int j = 0; !q.empty() && j < size; j++) {
                TreeNode* k = q.front();
                if (k != nullptr) {
                    if (k->left) {
                        q.push(k->left);
                    }
                    if (k->right) {
                        q.push(k->right);
                    }
                    l.push_back(k->val);
                }
                q.pop();
            }
            v.push_back(l);
        }
        return v;
    }
};
