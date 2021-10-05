bool isValidSequence(struct TreeNode* root, int* arr, int arrSize) {
    if (root == NULL && arrSize == 0) {
        return true;
    } else if (root == NULL || arrSize == 0) {
        return false;
    } else if (root->val != arr[0]) {
        return false;
    } else {
        if (root->left != NULL && root->right != NULL) {
            return isValidSequence(root->left, arr + 1, arrSize - 1) || isValidSequence(root->right, arr + 1, arrSize - 1);
        } else if (root->left != NULL) {
            return isValidSequence(root->left, arr + 1, arrSize - 1);
        } else {
            return isValidSequence(root->right, arr + 1, arrSize - 1);
        }
    }
}
