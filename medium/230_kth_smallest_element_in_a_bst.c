void dfs(struct TreeNode *root, int k, int *count, int *result) {
    if (root == NULL || *result >= 0) {
        return;
    }
    dfs(root->left, k, count, result);
    *count += 1;
    if (*count == k) {
        *result = root->val;
        return;
    }
    dfs(root->right, k, count, result);
}

int kthSmallest(struct TreeNode* root, int k) {
    int count = 0, result = -1;
    dfs(root, k, &count, &result);
    return result;
}
