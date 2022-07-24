bool is_mirror(struct TreeNode *node_1, struct TreeNode *node_2) {
    if (node_1 == NULL && node_2 == NULL) {
        return true;
    } else if (node_1 == NULL || node_2 == NULL) {
        return false;
    }
    return node_1->val == node_2->val && is_mirror(node_1->left, node_2->right) && is_mirror(node_1->right, node_2->left);
}

bool isSymmetric(struct TreeNode* root) {
    return is_mirror(root, root);
}
