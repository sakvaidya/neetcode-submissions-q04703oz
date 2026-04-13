class Codec {
public:
    // Encodes a tree to a single string using preorder traversal
    string serialize(TreeNode* root) {
        if (!root) return "N,";
        return to_string(root->val) + "," 
             + serialize(root->left) 
             + serialize(root->right);
    }

    // Helper: recursively rebuilds tree from token stream
    TreeNode* buildTree(queue<string>& tokens) {
        string token = tokens.front();
        tokens.pop();

        if (token == "N") return nullptr;

        TreeNode* node = new TreeNode(stoi(token));
        node->left  = buildTree(tokens);
        node->right = buildTree(tokens);
        return node;
    }

    // Decodes your encoded data to tree
    TreeNode* deserialize(string data) {
        queue<string> tokens;
        stringstream ss(data);
        string token;

        while (getline(ss, token, ',')) {
            tokens.push(token);
        }

        return buildTree(tokens);
    }
};