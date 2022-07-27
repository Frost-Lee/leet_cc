int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int left_max = maxDepth(root->left);
    int right_max = maxDepth(root->right);
    return (left_max > right_max ? left_max : right_max) + 1;
}
