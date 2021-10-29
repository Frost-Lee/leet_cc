class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        start, end = 0, len(arr) - 1
        while start <= end:
            middle = (start + end) // 2
            if arr[middle] == x:
                start = middle + 1
                end = middle
                break
            elif arr[middle] > x:
                end = middle - 1
            elif arr[middle] < x:
                start = middle + 1
        start_result, end_result = [], []
        print(start, end)
        while len(start_result) + len(end_result) < k:
            if 0 <= start < len(arr) and 0 <= end < len(arr):
                if abs(arr[start] - x) < abs(arr[end] - x):
                    start_result.append(arr[start])
                    start += 1
                else:
                    end_result.append(arr[end])
                    end -= 1
            elif 0 <= start < len(arr):
                start_result.append(arr[start])
                start += 1
            elif 0 <= end < len(arr):
                end_result.append(arr[end])
                end -= 1
        return [*reversed(end_result)] + start_result
