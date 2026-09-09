// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.length() < needle.length()) return -1;
        int i=0, j=0;
        while(j<haystack.length()){
            int k = j;
            while(i<needle.length() && needle[i] == haystack[j]){
                i++;
                j++;
            }
            if(i==needle.length()) return j - needle.length();
            else{
                i = 0; j = k+1;
            }
        }
        return -1;
    }
};