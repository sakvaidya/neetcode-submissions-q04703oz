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
    vector<int> ldr(TreeNode* ptr, vector<int> p) {
        if (!ptr) {
            return p;
        }
        if (ptr->left) {
            p = ldr(ptr->left, p);
        }
        p.push_back(ptr->val);
        if (ptr->right) {
            p = ldr(ptr->right, p);
        }
        return p;
    }
    int kthSmallest(TreeNode* root, int k) {
        if (!root) {return -1;}
        vector<int> p;
        p = ldr(root, p);
        if (p.size() < k) {
            return -1;
        } else {
            for (int i: p) {
                cout << i << endl;
            }
            return p[k-1];
        }
    }
};
