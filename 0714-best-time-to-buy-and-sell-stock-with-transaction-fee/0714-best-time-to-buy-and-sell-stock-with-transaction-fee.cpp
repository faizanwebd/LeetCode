class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int hold = -prices[0], cash = 0;
        for (int i = 1; i < n; ++i) {
            hold = max(hold, cash - prices[i]);
            cash = max(cash, hold + prices[i] - fee);
        }
        return cash;
    }
};
