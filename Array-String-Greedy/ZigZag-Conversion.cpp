// https://leetcode.com/problems/zigzag-conversion/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int j = 0, i = 0;
        bool forward = true;
        vector<vector<char>> x(numRows);
        while(i<s.length()){
            char ch = s[i];
            x[j].push_back(ch);
            if(j==numRows-1) forward = false;
            if(j==0) forward = true;
            if(forward) j++;
            else j--;
            i++;
        }

        string result = "";
        for(int i=0; i<x.size(); i++){
            vector<char> temp = x[i];
            for(auto it: temp) result+=it;
        }
        return result;
    }
};