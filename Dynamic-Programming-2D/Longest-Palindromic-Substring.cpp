// https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
public:
    // MEMOIZATION
    // int t[1001][1001]; // memoization
    // bool solve(string &s, int i, int j){
    //     if(i>=j) return 1;
    //     if(t[i][j]!=-1) return t[i][j];
    //     if(s[i] == s[j]) return t[i][j] = solve(s, i+1, j-1);
    //     return t[i][j] = 0;
    // }

    // string longestPalindrome(string s) {
    //     int n = s.length();
    //     memset(t, -1, sizeof(t));
    //     int maxLen = INT_MIN, sp = -1;
    //     for(int i=0; i<n; i++){
    //         for(int j=i; j<n; j++){
    //             if(solve(s, i, j)){
    //                 if(j - i + 1>maxLen){
    //                     maxLen = j - i + 1;
    //                     sp = i;
    //                 }
    //             }
    //         }
    //     }
    //     return s.substr(sp, maxLen);
    // }

    // BOTTOM UP:
    string longestPalindrome(string s){
        int n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n));
        int maxL = 0, idx = 0;
        for(int i=0; i<n; i++){
            t[i][i] = true;
            maxL = 1;
        }
        for(int L=2; L<=n;L++){
            for(int i=0; i<n-L+1; i++){
                int j = i+L-1;

                if(s[i] == s[j] && L == 2){
                    t[i][j] = true;
                    maxL = 2;
                    idx = i;
                } else if(s[i] == s[j] && t[i+1][j-1]){
                    t[i][j] = true;
                    if(j-i+1>maxL){
                        maxL = j-i+1;
                        idx = i;
                    }
                } else t[i][j] = false;
            }
        }
        return s.substr(idx, maxL);
    }
};