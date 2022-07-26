class Solution:
    def bst_next(self, node, target):
        if node is None:
            return None
        if target == node.val:
            return node
        elif target > node.val:
            return node.right
        elif target < node.val:
            return node.left

    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        p_path_nodes = set([root])
        p_path_node = root
        while p_path_node.val != p.val:
            p_path_node = self.bst_next(p_path_node, p.val)
            p_path_nodes.add(p_path_node)
        previous_node, q_path_node = root, root
        while q_path_node in p_path_nodes and q_path_node.val != q.val:
            previous_node = q_path_node
            q_path_node = self.bst_next(q_path_node, q.val)
        return previous_node if q_path_node not in p_path_nodes else q_path_node
