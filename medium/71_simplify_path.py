import collections
import re

class Solution:
    def simplifyPath(self, path: str) -> str:
        path = re.sub('/+', '/', path)
        elements = path.split('/')
        element_list = collections.deque()
        for element in elements:
            if len(element) == 0:
                continue
            if element == '.':
                pass
            elif element == '..':
                if len(element_list) > 0:
                    element_list.pop()
            else:
                element_list.append(element)
        return '/' + '/'.join(element_list)
