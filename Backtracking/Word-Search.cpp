// https://leetcode.com/problems/word-search/
// class Solution {
// public:
//     bool dfs(vector<vector<char>>& board, int r, int c, string& word, int idx){
//         if (idx == word.size()) return true;
//         int R = board.size(), C = board[0].size();
//         if (r<0 || c<0 || r>=R || c>=C ||
//             board[r][c] == '#' ||
//             board[r][c] != word[idx]) {
//             return false;
//         }
//         char ch = board[r][c];
//         board[r][c] = '#';
//         bool ok = dfs(board, r-1, c,   word, idx+1) || dfs(board, r,   c+1, word, idx+1) ||
//                   dfs(board, r+1, c,   word, idx+1) || dfs(board, r,   c-1, word, idx+1);
//         board[r][c] = ch;
//         return ok;
//     }

//     bool exist(vector<vector<char>>& board, string word) {
//         int R = board.size(), C = board[0].size();
//         for (int i = 0; i < R; ++i) {
//             for (int j = 0; j < C; ++j) {
//                 if (board[i][j] == word[0]) {
//                     if (dfs(board, i, j, word, 0))
//                         return true;
//                 }
//             }
//         }
//         return false;
//     }
// };
class Solution {
public:
    int dr[4] = {-1, 0, +1, 0};
    int dc[4] = {0, +1, 0, -1};
    bool dfs(int r, int c, string& word, int idx, vector<vector<char>>& board, vector<vector<bool>>& vis){
        if (idx == word.size()) return true;
        int R = board.size(), C = board[0].size();
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
            if (vis[nr][nc] || board[nr][nc] != word[idx]) continue;
            vis[nr][nc] = true;
            if (dfs(nr, nc, word, idx+1, board, vis)) return true;
            vis[nr][nc] = false;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int R = board.size(), C = board[0].size();
        vector<vector<bool>> vis(R, vector<bool>(C, false));
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (board[i][j] == word[0]) {
                    vis[i][j] = true;
                    if (dfs(i, j, word, 1, board, vis)) return true;
                    vis[i][j] = false;
                }
            }
        }
        return false;
    }
};
