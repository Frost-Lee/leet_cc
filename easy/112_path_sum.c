/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool hasPathSum(struct TreeNode* root, int sum){
    if (root == NULL) {
        return false;
    }
    if (root->left == NULL && root->right == NULL) {
        return root->val == sum;
    } else {
        int subSum = sum - root->val;
        if (root->left == NULL) {
            return hasPathSum(root->right, subSum);
        }
        if (root->right == NULL) {
            return hasPathSum(root->left, subSum);
        }
        return hasPathSum(root->left, subSum) || hasPathSum(root->right, subSum);
    }
}
