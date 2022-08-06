struct TreeNode* recursive_bst_construct(int *nums, int start, int end) {
    if (end < start) {
        return NULL;
    }
    int middle_index = (start + end) / 2;
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = nums[middle_index];
    node->left = recursive_bst_construct(nums, start, middle_index - 1);
    node->right = recursive_bst_construct(nums, middle_index + 1, end);
    return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return recursive_bst_construct(nums, 0, numsSize - 1);
}
