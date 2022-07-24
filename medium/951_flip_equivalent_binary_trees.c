bool flipEquiv(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    } else if (root1 == NULL || root2 == NULL) {
        return false;
    }
    return root1->val == root2->val && (
        (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
        (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left))
    );
}
