// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
// class Solution {
// public:
//     int helper(int idx, int buy, int cap, vector<vector<vector<int>>> &dp, int n, vector<int> &prices) {
//         if (idx == n || cap == 0) return 0;
//         if (dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
//         if (buy) {
//             return dp[idx][buy][cap] = max(
//                 helper(idx + 1, 1, cap, dp, n, prices),
//                 -prices[idx] + helper(idx + 1, 0, cap, dp, n, prices)
//             );
//         } else {
//             return dp[idx][buy][cap] = max(
//                 helper(idx + 1, 0, cap, dp, n, prices),
//                 prices[idx] + helper(idx + 1, 1, cap - 1, dp, n, prices)
//             );
//         }
//     }

//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
//         return helper(0, 1, 2, dp, n, prices);
//     }
// };


// TABULATION CODE
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int idx = 0; idx <= n; idx++) {  
            for (int buy = 0; buy <= 1; buy++) {
                dp[idx][buy][0] = 0;
            }
        }
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 0; cap <= 2; cap++) {
                dp[n][buy][cap] = 0;
            }
        }
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
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
        return dp[0][1][2];
    }
};
