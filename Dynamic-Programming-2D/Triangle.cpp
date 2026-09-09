// https://leetcode.com/problems/triangle
class Solution {
public:
    // MEMOIZATION + RECURSION
    // int n;
    // int t[201][201];
    // int solve(vector<vector<int>> &triangle, int row, int col){
    //     if(row == n-1) return triangle[row][col];
    //     if(t[row][col]!=-1) return t[row][col];
    //     int minPathSum = triangle[row][col] + min(solve(triangle, row+1, col), solve(triangle, row+1, col+1));
    //     return t[row][col] = minPathSum;
    // }

    int minimumTotal(vector<vector<int>>& triangle) {
        // Memorization
        // n = triangle.size();
        // memset(t, -1, sizeof(t));
        // return solve(triangle, 0, 0);
        
        // TABULATION: Bottom Up TC: O(N^2), SC: O(N^2)
        // int n = triangle.size();
        // vector<vector<int>> t = triangle;
        // for(int row = n-2; row>=0; row--){
        //     for(int col = 0; col<=row; col++){
        //         t[row][col] = t[row][col] + min(t[row+1][col], t[row+1][col+1]);
        //     }
        // }
        // return t[0][0];

        // SPACE OPTIMIZED
        int n = triangle.size();
        vector<int> t = triangle[n-1]; // space: O(N)
        for(int row = n-2; row>=0; row--) for(int col = 0; col<=row; col++) t[col] = triangle[row][col] + min(t[col], t[col+1]);
        return t[0];
    }
};