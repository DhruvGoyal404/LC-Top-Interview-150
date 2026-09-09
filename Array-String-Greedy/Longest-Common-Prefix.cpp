// https://leetcode.com/problems/longest-common-prefix/
class Solution {
public:
    bool check(char ch, vector<string> &strs, int idx) {
        for(int i = 0; i < strs.size(); i++) if(idx >= strs[i].size() || strs[i][idx] != ch) return false;
        return true;
    }

    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        for(int i = 0; i < strs[0].size(); i++) {
            char ch = strs[0][i];
            if(check(ch, strs, i)) result += ch;
            else break;
        }
        return result;
    }
};