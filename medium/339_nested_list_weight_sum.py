class Solution:
    def depthSum(self, nestedList: List[NestedInteger]) -> int:
        def recursive_sum(nest, depth):
            result = 0
            for n in nest:
                if n.isInteger():
                    result += depth * n.getInteger()
                else:
                    result += recursive_sum(n, depth + 1)
        return recursive_sum(nestedList, 1)
