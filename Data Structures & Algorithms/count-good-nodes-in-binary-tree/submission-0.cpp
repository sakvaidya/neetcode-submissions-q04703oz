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
    int gnodes(int c, int lm, TreeNode* root) {
        if (!root) {
            return c;
        }
        if (root->val >=  lm) {
            c++;
            lm = root->val;
        }
        if (root->left && root->right) {
            return gnodes(gnodes(c, lm, root->left), lm, root->right);
        } else if (root->left) {
            return gnodes(c, lm, root->left);
        } else if (root->right) {
            return gnodes(c, lm, root->right);
        } else {
            return c;
        }
    }
    int goodNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        else {
            return gnodes(0, root->val, root);
        }
    }
};
