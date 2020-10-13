struct TreeNode* lca = NULL;

bool dfs(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (!root) {
        return false;
    }
    bool targetInLeft = dfs(root->left, p, q);
    bool targetInRight = dfs(root->right, p, q);
    if ((targetInLeft && targetInRight) || ((targetInLeft || targetInRight) && (root == p || root == q))) {
        lca = root;
    }
    return targetInLeft || targetInRight || root == p || root == q;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    dfs(root, p, q);
    return lca;
}
