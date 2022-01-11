class Solution:
    def sequenceReconstruction(self, nums: List[int], sequences: List[List[int]]) -> bool:
        unique_numbers = list(set().union(*[*map(lambda x: set(x), sequences)]))
        if len(unique_numbers) != len(nums):
            return False
        adjacent_list = {number : [] for number in unique_numbers}
        indegree_map = {number : 0 for number in unique_numbers}
        relations = set()
        for sequence in sequences:
            for i in range(1, len(sequence)):
                relations.add((sequence[i - 1], sequence[i]))
        for relation in relations:
            adjacent_list[relation[0]].append(relation[1])
            indegree_map[relation[1]] += 1
        queue = [n for n in indegree_map.keys() if indegree_map[n] == 0]
        gt_nums = []
        while len(queue) > 0:
            if len(queue) != 1:
                return False
            popped_number = queue.pop(0)
            gt_nums.append(popped_number)
            for number in adjacent_list[popped_number]:
                indegree_map[number] -= 1
                if indegree_map[number] == 0:
                    queue.append(number)
        return gt_nums == nums
