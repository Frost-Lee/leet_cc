class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        max_heap, min_heap = [], []
        medians = []
        for i in range(len(nums)):
            if len(max_heap) == 0 or nums[i] <= -max_heap[0]:
                heapq.heappush(max_heap, -nums[i])
            else:
                heapq.heappush(min_heap, nums[i])
            self._heap_maintain(max_heap, min_heap)
            if len(max_heap) + len(min_heap) > k:
                window_tail_element = nums[i - k]
                if window_tail_element <= -max_heap[0]:
                    self._heap_remove(max_heap, -window_tail_element)
                else:
                    self._heap_remove(min_heap, window_tail_element)
                self._heap_maintain(max_heap, min_heap)
            if len(max_heap) + len(min_heap) >= k:

                if len(max_heap) == len(min_heap):
                    medians.append((-max_heap[0] + min_heap[0]) / 2)
                else:
  
                    assert len(max_heap) == len(min_heap) + 1
                    medians.append(-max_heap[0])
        return medians

    def _heap_maintain(self, max_heap, min_heap):
        while len(max_heap) > len(min_heap) + 1:
            heapq.heappush(min_heap, -max_heap[0])
            heapq.heappop(max_heap)
        while len(min_heap) > len(max_heap):
            heapq.heappush(max_heap, -min_heap[0])
            heapq.heappop(min_heap)

    def _heap_remove(self, heap, element):
        index = heap.index(element)
        heap[index] = heap[-1]
        heap.pop()
        heapq.heapify(heap)
