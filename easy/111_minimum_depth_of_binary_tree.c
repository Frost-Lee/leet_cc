int minDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else if (root->left == NULL && root->right == NULL) {
        return 1;
    } else {
        if (root->left != NULL && root->right != NULL) {
            int left_min = minDepth(root->left);
            int right_min = minDepth(root->right);
            return 1 + (left_min < right_min ? left_min : right_min);
        } else if (root->left == NULL) {
            return 1 + minDepth(root->right);
        } else {
            return 1 + minDepth(root->left);
        }
    }
}
