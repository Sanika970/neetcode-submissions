class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;   // buy
        int r = 1;   // sell
        int maxp = 0;

        while (r < prices.size()) {
            if (prices[r] > prices[l]) {
                int profit = prices[r] - prices[l];
                maxp = max(maxp, profit);
            } else {
                l = r;   // new buying day
            }
            r++;
        }

        return maxp;
    }
};