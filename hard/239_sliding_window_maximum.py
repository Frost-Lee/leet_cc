class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        result = []
        deq = deque()
        def clean_deque(i):
            nonlocal deq
            if deq and deq[0] <= i - k:
                deq.popleft()
            while deq and nums[i] > nums[deq[-1]]:
                deq.pop()
        for i in range(len(nums)):
            clean_deque(i)
            deq.append(i)
            if i >= k - 1:
                result.append(nums[deq[0]])
        return result
