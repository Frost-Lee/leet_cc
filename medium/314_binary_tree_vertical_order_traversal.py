import collections

class Solution:
    def verticalOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result_dict = {}
        if root is None:
            return []
        node_queue = collections.deque([(root, 0)])
        while len(node_queue) > 0:
            popped_node, shift = node_queue.popleft()
            if popped_node.left is not None:
                node_queue.append((popped_node.left, shift - 1))
            if popped_node.right is not None:
                node_queue.append((popped_node.right, shift + 1))
            if shift in result_dict:
                result_dict[shift].append(popped_node.val)
            else:
                result_dict[shift] = [popped_node.val]
        return [*map(lambda x: x[1], sorted([*result_dict.items()], key=lambda x: x[0]))]
