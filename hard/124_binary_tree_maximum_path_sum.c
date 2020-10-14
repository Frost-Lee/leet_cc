int max(int a, int b) {return a > b ? a : b;}

int maxPathSum(struct TreeNode* root) {
    int current_max = INT_MIN;
    subMaxPathSum(root, &current_max);
    return current_max;
}

int subMaxPathSum(struct TreeNode* root, int* current_max) {
    if (!root) {return 0;}
    int left_path_sum = max(subMaxPathSum(root->left, current_max), 0);
    int right_path_sum = max(subMaxPathSum(root->right, current_max), 0);
    int bend_sum = root->val + left_path_sum + right_path_sum;
    *current_max = max(*current_max, bend_sum);
    return root->val + max(left_path_sum, right_path_sum);
}
