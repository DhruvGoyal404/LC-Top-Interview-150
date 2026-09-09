// https://leetcode.com/problems/word-break/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // If dp[j] is true and substring s[j..i-1] is in dict, then dp[i] is true
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break; // Move to the next i once a valid break is found
                }
            }
        }

        return dp[n];
    }
};