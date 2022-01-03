class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        left_index = bisect.bisect_left(arr, x) - 1
        right_index = left_index + 1
        left_result, right_result = [], []
        while len(left_result) + len(right_result) < k:
            if 0 <= left_index < len(arr) and 0 <= right_index < len(arr):
                if abs(arr[left_index] - x) <= abs(arr[right_index] - x):
                    left_result.append(arr[left_index])
                    left_index -= 1
                else:
                    right_result.append(arr[right_index])
                    right_index += 1
            elif 0 <= left_index < len(arr):
                left_result.append(arr[left_index])
                left_index -= 1
            elif 0 <= right_index < len(arr):
                right_result.append(arr[right_index])
                right_index += 1
        return [*reversed(left_result)] + right_result
