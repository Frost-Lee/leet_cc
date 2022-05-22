class Solution:
    def nodeDepth(self, node):
        depth = 0
        while node is not None:
            node = node.parent
            depth += 1
        return depth

    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        p_depth, q_depth = self.nodeDepth(p), self.nodeDepth(q)
        while p_depth > q_depth:
            p = p.parent
            p_depth -= 1
        while q_depth > p_depth:
            q = q.parent
            q_depth -= 1
        while id(p) != id(q):
            p = p.parent
            q = q.parent
        return p
