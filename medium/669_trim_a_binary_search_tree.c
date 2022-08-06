struct TreeNode* trimBST(struct TreeNode* root, int low, int high) {
    if (root == NULL) {
        return NULL;
    }
    if (root->val < low) {
        return trimBST(root->right, low, high);
    } else if (root->val > high) {
        return trimBST(root->left, low, high);
    } else {
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
}
