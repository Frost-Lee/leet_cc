int closestValue(struct TreeNode* root, double target) {
    int closest = root->val;
    while (root) {
        closest = fabs(target - (double)root->val) < fabs(target - (double)closest) ? root->val : closest;
        if (root->val < target) {
            root = root->right;
        } else if (root->val > target) {
            root = root->left;
        } else {
            break;
        }
    }
    return closest;
}
