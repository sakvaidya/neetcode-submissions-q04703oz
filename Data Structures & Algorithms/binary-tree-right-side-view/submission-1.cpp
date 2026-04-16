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
    vector<int> rightSideView(TreeNode* root) {
       vector<int> out;
       queue<TreeNode*> q;
       if (!root) {
        return {};
       }
       q.push(root);
       while(!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* ptr = q.front();
                cout << ptr->val << endl;
                q.pop();
                if (ptr->left) {
                    q.push(ptr->left);
                }
                if (ptr->right) {
                    q.push(ptr->right);
                }
                if (i == size-1) {
                    cout << "l" << ptr->val << endl;
                    out.push_back(ptr->val);
                }
            }
        }
        return out; 
    }
};
