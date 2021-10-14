int max_length = 0;

void recursive_consecutive(struct TreeNode *root, struct TreeNode *parent, int length) {
    if (root == NULL) {
        return length;
    }
    if (parent != NULL && root->val == parent->val + 1) {
        length += 1;
    } else {
        length = 1;
    }
    max_length = max_length > length ? max_length : length;
    recursive_consecutive(root->left, root, length);
    recursive_consecutive(root->right, root, length);
}

int longestConsecutive(struct TreeNode* root) {
    max_length = 0;
    recursive_consecutive(root, NULL, 0);
    return max_length;
}
