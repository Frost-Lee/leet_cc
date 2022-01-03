class Solution:
    def reorganizeString(self, s: str) -> str:
        counter = Counter(s)
        heap = [(-counter[k], k) for k in counter.keys()]
        heapq.heapify(heap)
        result_string = ''
        temp_element = None
        while len(heap) > 0:
            old_element = temp_element
            temp_element = heapq.heappop(heap)
            result_string += temp_element[1]
            temp_element = (temp_element[0] + 1, temp_element[1]) if temp_element[0] + 1 < 0 else None
            if old_element is not None:
                heapq.heappush(heap, old_element)
        return result_string if temp_element is None else ''
