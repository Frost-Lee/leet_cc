class MedianFinder:

    def __init__(self):
        self.min_heap = []
        self.max_heap = []

    def addNum(self, num: int) -> None:
        if len(self.max_heap) == 0 or len(self.min_heap) == 0:
            heapq.heappush(self.max_heap, -num)
        elif num <= -self.max_heap[0]:
            heapq.heappush(self.max_heap, -num)
        elif num >= self.min_heap[0]:
            heapq.heappush(self.min_heap, num)
        else:
            heapq.heappush(self.max_heap, -num)
        if len(self.max_heap) > len(self.min_heap) + 1:
            temp = -heapq.heappop(self.max_heap)
            heapq.heappush(self.min_heap, temp)
        elif len(self.min_heap) > len(self.max_heap):
            temp = heapq.heappop(self.min_heap)
            heapq.heappush(self.max_heap, -temp)

    def findMedian(self) -> float:
        if len(self.max_heap) == len(self.min_heap):
            return (-self.max_heap[0] + self.min_heap[0]) / 2
        else:
            return -self.max_heap[0]
