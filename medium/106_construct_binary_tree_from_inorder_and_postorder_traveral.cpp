class Solution {
public:
    std::map<int, size_t> value_index_map;

    TreeNode *recursive_build(std::vector<int>& inorder, std::vector<int>& postorder, size_t start, size_t end) {
        if (start > end) {
            return NULL;
        }
        int root_value = postorder.back();
        postorder.pop_back();
        struct TreeNode *root = new TreeNode(root_value);
        size_t split_index = this->value_index_map[root_value];
        root->right = recursive_build(inorder, postorder, split_index + 1, end);
        root->left = split_index == 0 ? NULL : recursive_build(inorder, postorder, start, split_index - 1);
        return root;
    }

    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        if (inorder.size() == 0) {
            return NULL;
        }
        for (size_t i = 0; i < inorder.size(); i ++) {
            this->value_index_map[inorder[i]] = i;
        }
        return recursive_build(inorder, postorder, 0, inorder.size() - 1);
    }
};
