class Solution:
    def threeSumMulti(self, arr: List[int], target: int) -> int:
        base = 10 ** 9 + 7
        result = 0
        arr = sorted(arr)
        for i in range(len(arr)):
            start, end = i + 1, len(arr) - 1
            remaining = target - arr[i]
            while start < end:
                partial_sum = arr[start] + arr[end]
                if partial_sum < remaining:
                    start += 1
                elif partial_sum > remaining:
                    end -= 1
                elif arr[start] == arr[end]:
                    result += (end - start + 1) * (end - start) // 2
                    result %= base
                    break
                else:
                    start_duplication, end_duplication = 1, 1
                    while start + 1 < end and arr[start] == arr[start + 1]:
                        start_duplication += 1
                        start += 1
                    while end - 1 > start and arr[end] == arr[end - 1]:
                        end_duplication += 1
                        end -= 1
                    result += start_duplication * end_duplication
                    result %= base
                    start += 1
                    end -= 1
        return result
