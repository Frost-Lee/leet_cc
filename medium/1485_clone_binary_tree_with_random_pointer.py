class Solution:
    def copyRandomBinaryTree(self, root: 'Optional[Node]') -> 'Optional[NodeCopy]':
        node_id_map = {}
        def copy_tree(node):
            nonlocal node_id_map
            if node is None:
                return None
            new_node = NodeCopy(node.val)
            new_node.left = copy_tree(node.left)
            new_node.right = copy_tree(node.right)
            node_id_map[id(node)] = new_node
            return new_node
        new_root = copy_tree(root)
        def set_random_pointer(node):
            nonlocal node_id_map
            if node is None:
                return None
            if node.random is None:
                node_id_map[id(node)].random = None
            else:
                node_id_map[id(node)].random = node_id_map[id(node.random)]
            set_random_pointer(node.left)
            set_random_pointer(node.right)
        set_random_pointer(root)
        return new_root
