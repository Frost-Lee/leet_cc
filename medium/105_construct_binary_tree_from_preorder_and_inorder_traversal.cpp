class Solution {
public:
    std::map<int, size_t> value_index_map;
    size_t preorder_offset;

    TreeNode *recursive_build(std::vector<int> &preorder, std::vector<int> &inorder, size_t start, size_t end) {
        if (start > end) {
            return NULL;
        }
        struct TreeNode *root = new struct TreeNode(preorder[this->preorder_offset]);
        size_t split_index = this->value_index_map[preorder[this->preorder_offset]];
        this->preorder_offset += 1;
        // cautions for size_t negative overflow
        root->left = split_index == 0 ? NULL : recursive_build(preorder, inorder, start, split_index - 1);
        root->right = recursive_build(preorder, inorder, split_index + 1, end);
        return root;
    }

    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        if (preorder.size() == 0) {
            return NULL;
        }
        for (size_t i = 0; i < inorder.size(); i ++) {
            this->value_index_map[inorder[i]] = i;
        }
        this->preorder_offset = 0;
        return this->recursive_build(preorder, inorder, 0, preorder.size() - 1);
    }
};
