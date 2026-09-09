// https://leetcode.com/problems/maximal-square/
// TABULATION:
// class Solution {
// public:
//     int maximalSquare(vector<vector<char>>& matrix) {
//         int m = matrix.size(), n = matrix[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, 0));

//         int maxi = 0;

//         for(int i = m - 1; i >= 0; i--){
//             for(int j = n - 1; j >= 0; j--){

//                 if(matrix[i][j] == '1'){
//                     if(i == m - 1 || j == n - 1){
//                         dp[i][j] = 1;
//                     }
//                     else{
//                         dp[i][j] = 1 + min({
//                             dp[i][j+1],
//                             dp[i+1][j],
//                             dp[i+1][j+1]
//                         });
//                     }

//                     maxi = max(maxi, dp[i][j]);
//                 }
//             }
//         }

//         return maxi * maxi;
//     }
// };

class Solution {
public:
    int solveMem(vector<vector<char>>& mat, int i, int j, int &maxi, vector<vector<int>>& dp) {
        if (i >= mat.size() || j >= mat[0].size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int right = solveMem(mat, i, j + 1, maxi, dp);
        int diagonal = solveMem(mat, i + 1, j + 1, maxi, dp);
        int down = solveMem(mat, i + 1, j, maxi, dp);
        if (mat[i][j] == '1') {
            dp[i][j] = 1 + min({right, diagonal, down});
            maxi = max(maxi, dp[i][j]);
        } else dp[i][j] = 0;
        return dp[i][j];
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int maxi = 0;
        solveMem(matrix, 0, 0, maxi, dp);
        return maxi * maxi;
    }
};
