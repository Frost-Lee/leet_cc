class Solution:
    def node_depth(self, node):
        depth = 0
        while node.parent is not None:
            node = node.parent
            depth += 1
        return depth

    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        p_depth, q_depth = self.node_depth(p), self.node_depth(q)
        if p_depth > q_depth:
            p, q = q, p
            p_depth, q_depth = q_depth, p_depth
        depth_difference = q_depth - p_depth
        while depth_difference > 0:
            q = q.parent
            depth_difference -= 1
        while p.val != q.val:
            p = p.parent
            q = q.parent
        return p
