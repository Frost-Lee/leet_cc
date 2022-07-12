class Solution:
    def djs_find(self, disjoint_set, index):
        while disjoint_set[index] >= 0:
            index = disjoint_set[index]
        return index

    def djs_union(self, disjoint_set, index_1, index_2):
        assert disjoint_set[index_1] < 0
        assert disjoint_set[index_2] < 0
        if -disjoint_set[index_1] > -disjoint_set[index_2]:
            index_1, index_2 = index_2, index_1
        disjoint_set[index_2] += disjoint_set[index_1]
        disjoint_set[index_1] = index_2

    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        disjoint_set = [-1 for _ in range(n)]
        for edge in edges:
            source_index = self.djs_find(disjoint_set, edge[0])
            destination_index = self.djs_find(disjoint_set, edge[1])
            if source_index != destination_index:
                self.djs_union(disjoint_set, source_index, destination_index)
        return len([*filter(lambda x: x < 0, disjoint_set)])
