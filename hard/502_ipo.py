class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        capital_profits = [*zip(capital, profits)]
        capital_profits = sorted(capital_profits, key=lambda x: x[0])
        achieved_capital = w
        profit_heap = []
        for _ in range(k):
            while len(capital_profits) > 0 and capital_profits[0][0] <= achieved_capital:
                heapq.heappush(profit_heap, -capital_profits.pop(0)[1])
            if len(profit_heap) > 0:
                achieved_capital += -heapq.heappop(profit_heap)
            else:
                break
        return achieved_capital
