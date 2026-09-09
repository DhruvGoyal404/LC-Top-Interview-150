// https://leetcode.com/problems/n-queens-ii/description/
class Solution {
public:
    int possible = 0;
    vector<bool> cols;
    vector<bool> diag1;
    vector<bool> diag2;
    
    void solve(int n, int row) {
        if(row == n){
            possible++;
            return;
        }
        for(int col = 0; col < n; col++){
            if(!cols[col] && !diag1[row - col + n - 1] && !diag2[row + col]) {
                cols[col] = true;
                diag1[row - col + n - 1] = true;
                diag2[row + col] = true;
                solve(n, row + 1);
                cols[col] = false;
                diag1[row - col + n - 1] = false;
                diag2[row + col] = false;
            }
        }
    }

    int totalNQueens(int n) {
        cols.resize(n, false);
        diag1.resize(2*n - 1, false);
        diag2.resize(2*n - 1, false);
        solve(n, 0);
        return possible;
    }
};