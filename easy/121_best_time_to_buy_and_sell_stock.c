int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 0) {
        return 0;
    }
    int previous_lowest = prices[0];
    int max_profit = 0;
    for (int i = 0; i < pricesSize; i ++) {
        if (prices[i] - previous_lowest > max_profit) {
            max_profit = prices[i] - previous_lowest;
        }
        if (prices[i] < previous_lowest) {
            previous_lowest = prices[i];
        }
    }
    return max_profit;
}
