class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if head is None:
            return None
        original_nodes, copied_nodes = [], []
        tail = head
        while tail is not None:
            original_nodes.append(tail)
            copied_nodes.append(Node(tail.val, None, None))
            tail = tail.next
            original_nodes[-1].next = copied_nodes[-1]
        for index, node in enumerate(copied_nodes[:-1]):
            node.next = copied_nodes[index + 1]
        for index in range(len(original_nodes)):
            try:
                copied_nodes[index].random = original_nodes[index].random.next
            except AttributeError:
                copied_nodes[index].random = None
        for index, node in enumerate(original_nodes[:-1]):
            node.next = original_nodes[index + 1]
        return copied_nodes[0]
