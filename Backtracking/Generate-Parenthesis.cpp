// https://leetcode.com/problems/generate-parentheses/
class Solution {
public:
    void dfs(int n, int open, int close, string word, vector<string> &result){
        if(open==n && close==n){
            result.push_back(word);
            return;
        }
        if(open<n) dfs(n, open+1, close, word+'(', result);
        if (close<open) dfs(n, open, close+1, word+')', result);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        dfs(n, 0, 0, "", results);
        return results;
    }
};