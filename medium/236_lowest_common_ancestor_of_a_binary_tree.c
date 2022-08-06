bool dfs(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q, struct TreeNode **result) {
    if (root == NULL || *result != NULL) {
        return 0;
    }
    short middle = (short)(root == p || root == q);
    short left = (short)(dfs(root->left, p, q, result));
    short right = (short)(dfs(root->right, p, q, result));
    short state_sum = middle + left + right;
    if (state_sum >= 2) {
        *result = root;
    }
    return state_sum > 0;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode *result = NULL;
    dfs(root, p, q, &result);
    return result;
}
