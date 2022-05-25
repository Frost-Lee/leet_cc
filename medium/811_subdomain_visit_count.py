import collections
class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        domain_tree_root = ['', 0, {}]
        for cpdomain in cpdomains:
            root = domain_tree_root
            count, domain = cpdomain.split(' ')
            count = int(count)
            for element in reversed(domain.split('.')):
                if element not in root[2]:
                    root[2][element] = [element, 0, {}]
                root = root[2][element]
                root[1] += count
        result = []
        def dfs(root, parent_elements):
            nonlocal result
            new_parent_elements = parent_elements
            if len(root[0]) > 0:
                new_parent_elements.appendleft(root[0])
                result.append('{} {}'.format(root[1], '.'.join(new_parent_elements)))
            for child in root[2].values():
                dfs(child, new_parent_elements)
            if len(root[0]) > 0:
                new_parent_elements.popleft()
        dfs(domain_tree_root, collections.deque())
        return result
