struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        return NULL;
    }
    if (root->val > val) {
        return searchBST(root->left, val);
    } else if (root->val < val) {
        return searchBST(root->right, val);
    } else {
        return root;
    }
}
