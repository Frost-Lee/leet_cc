class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        union_find_list = [-1 for _ in range(26)]
        min_letter_map = {i : chr(ord('a') + i) for i in range(26)}
        def find(uf_list, letter):
            index = ord(letter) - ord('a')
            while uf_list[index] >= 0:
                index = uf_list[index]
            return index
        def union(uf_list, letter_1, letter_2):
            nonlocal min_letter_map
            index_1 = find(uf_list, letter_1)
            index_2 = find(uf_list, letter_2)
            if index_1 == index_2:
                return
            if -uf_list[index_1] < -uf_list[index_2]:
                index_1, index_2 = index_2, index_1
            size_2 = -uf_list[index_2] - 1
            uf_list[index_2] = index_1
            uf_list[index_1] -= size_2
            min_letter_map[index_1] = min(min_letter_map[index_1], min_letter_map[index_2])
            min_letter_map.pop(index_2, None)
        for letter_1, letter_2 in zip(s1, s2):
            union(union_find_list, letter_1, letter_2)
        result = ''
        for i in range(len(baseStr)):
            result += min_letter_map[find(union_find_list, baseStr[i])]
        return result
