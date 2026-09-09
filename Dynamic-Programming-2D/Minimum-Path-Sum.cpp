// https://leetcode.com/problems/minimum-path-sum
// class Solution {
// public:
//     int helperMemoization(vector<vector<int>> &dp, int i, int j, vector<vector<int>> &grid) {
//         if (i < 0 || j < 0) return INT_MAX;  
//         if (i == 0 && j == 0) return grid[i][j];
//         if (dp[i][j] != -1) return dp[i][j];

//         return dp[i][j] = grid[i][j] + min(
//             helperMemoization(dp, i - 1, j, grid),
//             helperMemoization(dp, i, j - 1, grid)
//             );
//     }

//     int minPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> dp(n, vector<int>(m, -1));

//         return helperMemoization(dp, n - 1, m - 1, grid);
//     }
// };
class Solution {
public:
    // Memoization (Top-Down DP)
    int helperMemoization(vector<vector<int>> &dp, int i, int j, vector<vector<int>> &grid) {
        if (i < 0 || j < 0) return INT_MAX;  
        if (i == 0 && j == 0) return grid[i][j];
        if (dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = grid[i][j] + min(
            helperMemoization(dp, i - 1, j, grid),
            helperMemoization(dp, i, j - 1, grid)
        );
    }

    // Tabulation (Bottom-Up DP)
    int helperTabular(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = grid[0][0];
        for (int j = 1; j < m; j++)
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        for (int i = 1; i < n; i++)
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n - 1][m - 1];
    }

    // Space Optimized (1D DP)
    int helperSC(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> prev(m, 0);

        prev[0] = grid[0][0];
        for (int j = 1; j < m; j++) prev[j] = prev[j - 1] + grid[0][j];

        for (int i = 1; i < n; i++) {
            vector<int> curr(m, 0);
            curr[0] = prev[0] + grid[i][0];

            for (int j = 1; j < m; j++)
                curr[j] = grid[i][j] + min(prev[j], curr[j - 1]);

            prev = curr;
        }

        return prev[m - 1];
    }

    int minPathSum(vector<vector<int>>& grid) {
        // vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        // return helperMemoization(dp, grid.size() - 1, grid[0].size() - 1, grid);
        return helperTabular(grid);
        // return helperSC(grid);
    }
};
