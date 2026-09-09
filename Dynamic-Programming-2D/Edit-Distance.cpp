// https://leetcode.com/problems/edit-distance/
class Solution {
public:
    int solve(vector<vector<int>> &dp, string word1, string word2, int i, int j, int n, int m){
        if(i == n) return m - j;
        if(j == m) return n - i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i] == word2[j]) dp[i][j] = solve(dp, word1, word2, i+1, j+1, n, m);
        else{
            dp[i][j] = 1+min(solve(dp, word1, word2, i+1, j+1, n, m),
            min(solve(dp, word1, word2, i+1, j, n, m), solve(dp, word1, word2, i, j+1, n, m)));
        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(dp, word1, word2, 0, 0, n, m);
    }
};