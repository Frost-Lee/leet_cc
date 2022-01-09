class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        heap = []
        for i in range(0, min(k, len(nums1))):
            for j in range(0, min(k, len(nums2))):
                if len(heap) < k:
                    heapq.heappush(heap, (-(nums1[i] + nums2[j]), nums1[i], nums2[j]))
                else:
                    if nums1[i] + nums2[j] > -heap[0][0]:
                        break
                    else:
                        heapq.heappop(heap)
                        heapq.heappush(heap, (-(nums1[i] + nums2[j]), nums1[i], nums2[j]))
        return [[pair[1], pair[2]] for pair in heap]
