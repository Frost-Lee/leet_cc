bool is_same_tree(struct TreeNode *node_1, struct TreeNode *node_2) {
    if (node_1 == NULL && node_2 == NULL) {
        return true;
    } else if (node_1 == NULL || node_2 == NULL) {
        return false;
    }
    return node_1->val == node_2->val && is_same_tree(node_1->left, node_2->left) && is_same_tree(node_1->right, node_2->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (subRoot == NULL) {
        return true;
    } else if (root == NULL) {
        return false;
    }
    return is_same_tree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
