int diameter = 0;

int tree_depth(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    int left_depth = tree_depth(root->left);
    int right_depth = tree_depth(root->right);
    diameter = diameter > left_depth + right_depth ? diameter : left_depth + right_depth;
    return (left_depth > right_depth ? left_depth : right_depth) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    diameter = 0;
    tree_depth(root);
    return diameter;
}
