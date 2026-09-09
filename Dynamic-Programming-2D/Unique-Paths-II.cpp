// https://leetcode.com/problems/unique-paths-ii/
class Solution {
public:
    int helperMemoization(vector<vector<int>> &dp, int i, int j, vector<vector<int>> &obstacleGrid) {
        if (i < 0 || j < 0) return 0;  
        if (obstacleGrid[i][j] == 1) return 0;
        if (i == 0 && j == 0) return 1;  
        if (dp[i][j] != -1) return dp[i][j];  
        return dp[i][j] = helperMemoization(dp,i-1,j,obstacleGrid)+helperMemoization(dp,i,j-1,obstacleGrid);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));  
        return helperMemoization(dp, n - 1, m - 1, obstacleGrid);  
    }
};