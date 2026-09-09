// https://leetcode.com/problems/interleaving-string
class Solution {
public:
    bool solve(string &s1, string &s2, string &s3, int l1, int l2, vector<vector<int>> &dp, int i, int j){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==l1 && j==l2) return dp[i][j] = true;;
        bool left = false, right = false;
        if(i<l1 && s1[i] == s3[i+j]) left = solve(s1, s2, s3, l1, l2, dp, i+1, j);
        if(j<l2 && s2[j] == s3[i+j]) right = solve(s1, s2, s3, l1, l2, dp, i, j+1);
        return dp[i][j] = left || right;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length(); 
        if(n+m!=s3.length()) return false;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(s1, s2, s3, n, m, dp, 0, 0);
    }
};