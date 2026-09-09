// https://leetcode.com/problems/game-of-life/
// class Solution {
// public:
//     int findCount(int i, int j, vector<vector<int>> &board, vector<int> dr, vector<int> dc){
//         int cnt = 0;
//         for(int k=0; k<dr.size(); k++){
//             if((i+dr[k]>=0 && i+dr[k]<board.size()) && (j+dc[k]>=0 && j+dc[k]<board[0].size()) 
//                             && board[i+dr[k]][j+dc[k]]) cnt++;
//         }
//         return cnt;
//     }

//     void gameOfLife(vector<vector<int>>& board) {
//         vector<int> dr = {-1, -1, -1, 0, 0, +1, +1, +1};
//         vector<int> dc = {-1, 0, +1, -1, +1, -1, 0, +1};
//         vector<vector<int>> decisions(board.size(), vector<int>(board[0].size()));
        
//         for(int i=0; i<board.size(); i++){
//             for(int j=0; j<board[0].size(); j++){
//                 int count = findCount(i, j, board, dr, dc);
//                 if(board[i][j] == 1) decisions[i][j] = (count < 2 || count > 3) ? 3 : 1;
//                 else decisions[i][j] = (count == 3) ? 2 : 0;
//             }
//         }
        
//         for(int i=0; i<board.size(); i++){
//             for(int j=0; j<board[0].size(); j++){
//                 board[i][j] = decisions[i][j];
//             }
//         }
        
//         for(int i=0; i<board.size(); i++) {
//             for(int j=0; j<board[0].size(); j++) {
//                 board[i][j] = (board[i][j] >= 2) ? 1 : 0;
//             }
//         }
//     }
// };

class Solution {
public:
    int findCount(int i, int j, vector<vector<int>> &board, vector<int> dr, vector<int> dc){
        int cnt = 0;
        for(int k=0; k<dr.size(); k++) if((i+dr[k]>=0 && i+dr[k]<board.size()) && (j+dc[k]>=0 && j+dc[k]<board[0].size()) && board[i+dr[k]][j+dc[k]]) cnt++;
        return cnt;
    }

    void gameOfLife(vector<vector<int>>& board) {
        vector<int> dr = {-1, -1, -1, 0, 0, +1, +1, +1};
        vector<int> dc = {-1, 0, +1, -1, +1, -1, 0, +1};
        vector<vector<int>> original = board;
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                int count = findCount(i, j, original, dr, dc);
                if(original[i][j] == 1) {
                    board[i][j] = (count == 2 || count == 3) ? 1 : 0;
                } else {
                    board[i][j] = (count == 3) ? 1 : 0;
                }
            }
        }
    }
};