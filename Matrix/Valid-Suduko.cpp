// https://leetcode.com/problems/valid-sudoku/
class Solution {
public:
    bool checkRow(vector<vector<char>> &board, int i, int j){
        for(int k=0; k<9; k++) if(k!=j && board[i][k] == board[i][j]) return false;
        return true;
    }

    bool checkCol(vector<vector<char>> &board, int i, int j){
        for(int k=0; k<9; k++) if(k!=i && board[k][j] == board[i][j]) return false;
        return true;
    }

    bool checkBox(vector<vector<char>> &board, int i, int j){
        int startRow = (i / 3) * 3, startCol = (j / 3) * 3;
        for(int r = startRow; r < startRow + 3; r++){
            for(int c = startCol; c < startCol + 3; c++){
                if((r != i || c != j) && board[r][c] == board[i][j])
                    return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.') continue;
                bool check1 = checkRow(board, i, j);
                bool check2 = checkCol(board, i, j);
                bool check3 = checkBox(board, i, j);
                if(check1 == false || check2 == false || check3 == false) return false;
            }
        }
        return true;
    }
};