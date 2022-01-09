class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        heap = [(nums[i][0], i, 0) for i in range(len(nums))]
        heapq.heapify(heap)
        heap_max = max([*map(lambda x: x[0], heap)])
        min_range = [heap[0][0], heap_max]
        while True:
            element = heapq.heappop(heap)
            if len(nums[element[1]]) > element[2] + 1:
                new_element = (nums[element[1]][element[2] + 1], element[1], element[2] + 1)
                heapq.heappush(heap, new_element)
                if new_element[0] > heap_max:
                    heap_max = new_element[0]
                if heap_max - heap[0][0] < min_range[1] - min_range[0]:
                    min_range = [heap[0][0], heap_max]
            else:
                break
        return min_range
