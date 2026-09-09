// https://leetcode.com/problems/jump-game-ii/
class Solution {
public:
    int jump(vector<int>& nums) {
        // DP BASED SOLUTION
        // int n = nums.size();
        // vector<int> dp(n, INT_MAX);
        // dp[0] = 0;
        // for(int i = 0; i < n; i++) for(int j = 1; j <= nums[i] && i + j < n; j++) dp[i + j] = min(dp[i + j], dp[i] + 1);
        // return dp[n - 1];

        // GREEDY BASED SOLUTION!!
        // O(N) and O(1)
        int jumps = 0, l = 0, r = 0;
        while(r<nums.size()-1){
            int farthest = 0;
            for(int idx = l; idx <= r; idx++) farthest = max(idx+nums[idx], farthest);
            jumps++; l = r+1; r = farthest;
        }
        return jumps;
    }
};