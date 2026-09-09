// https://leetcode.com/problems/coin-change/description
class Solution {
public:
    int coinsK(vector<int> &coins, int amount, vector<int> &dp){
        if(amount < 0) return INT_MAX;
        if(amount == 0) return 0;
        if(dp[amount] != -1) return dp[amount];
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++) mini = min(mini, coinsK(coins, amount - coins[i], dp));
        if(mini == INT_MAX) return dp[amount] = INT_MAX;
        return dp[amount] = mini + 1;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int ans = coinsK(coins, amount, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};