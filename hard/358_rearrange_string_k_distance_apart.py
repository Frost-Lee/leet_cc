class Solution:
    def rearrangeString(self, s: str, k: int) -> str:
        counter = Counter(s)
        heap = [(-counter[k], k) for k in counter.keys()]
        heapq.heapify(heap)
        result_string = ''
        temp_element_queue = []
        while len(heap) > 0:
            new_temp_element = heapq.heappop(heap)
            result_string += new_temp_element[1]
            temp_element_queue.append((new_temp_element[0] + 1, new_temp_element[1]))
            if len(temp_element_queue) >= k:
                element = temp_element_queue.pop(0)
                if element[0] < 0:
                    heapq.heappush(heap, element)
        return result_string if len(result_string) == len(s) else ''
