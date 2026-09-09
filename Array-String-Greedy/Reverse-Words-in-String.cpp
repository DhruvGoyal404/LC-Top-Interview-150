// https://leetcode.com/problems/reverse-words-in-a-string/description/
class Solution {
public:
    string reverseWords(string s) {
        string output = "";
        int j = s.length() - 1;
        while(j>=0){
            string temp = "";
            while(j>=0 && s[j] == ' ') j--;
            while(j >= 0 && s[j] != ' ') temp+=s[j--];
            reverse(temp.begin(), temp.end());
            output += temp;
            while(j >= 0 && s[j] == ' ') j--;
            if(j >= 0) output += ' ';
        }
        return output;
    }
};