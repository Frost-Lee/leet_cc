class Solution:
    def alienOrder(self, words: List[str]) -> str:
        adjacent_list, indegree_map = {}, {}
        unique_chars = set(''.join(words))
        for unique_char in unique_chars:
            adjacent_list[unique_char] = []
            indegree_map[unique_char] = 0
        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                is_relation_added = False
                for k in range(min(len(words[i]), len(words[j]))):
                    if words[i][k] != words[j][k]:
                        adjacent_list[words[i][k]].append(words[j][k])
                        indegree_map[words[j][k]] += 1
                        is_relation_added = True
                        break
                if not is_relation_added and len(words[i]) > len(words[j]):
                    return ''
        queue = [c for c in indegree_map.keys() if indegree_map[c] == 0]
        result_string = ''
        while len(queue) > 0:
            c = queue.pop(0)
            result_string += c
            for adjacent_c in adjacent_list[c]:
                indegree_map[adjacent_c] -= 1
                if indegree_map[adjacent_c] == 0:
                    queue.append(adjacent_c)
        return result_string if len(result_string) == len([*indegree_map.keys()]) else ''
