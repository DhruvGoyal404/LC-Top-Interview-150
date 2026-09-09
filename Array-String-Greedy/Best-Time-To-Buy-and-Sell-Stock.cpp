// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minimum = prices[0];
        for(int i=1;i<prices.size();i++){
            profit = max(profit, prices[i]-minimum);
            minimum = min(minimum, prices[i]);
        }
        return profit;
    }
};