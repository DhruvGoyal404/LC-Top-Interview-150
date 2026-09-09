// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        for(int idx = 0; idx <= n; idx ++){
            for(int buy = 0; buy<=1; buy++){
                dp[idx][buy][0] = 0;
            }
        }
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 0; cap <= k; cap++) {
                dp[n][buy][cap] = 0;
            }
        }
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {
                    if (buy) {
                        dp[idx][buy][cap] = max(
                            dp[idx + 1][1][cap],
                            -prices[idx] + dp[idx + 1][0][cap]
                        );
                    } else {
                        dp[idx][buy][cap] = max(
                            dp[idx + 1][0][cap], 
                            prices[idx] + dp[idx + 1][1][cap - 1]
                        );
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};