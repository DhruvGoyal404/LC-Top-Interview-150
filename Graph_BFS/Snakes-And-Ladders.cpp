// https://leetcode.com/problems/snakes-and-ladders/
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size(), moves = 0;
        queue<int> q;
        q.push(1);
        vector<int> dx = {+1, +2, +3, +4, +5, +6};
        vector<int> visited(n*n + 1, -1);
        visited[1] = 0;
        while(!q.empty()){
            int level = q.size();
            while(level--){
                int k = q.front();
                q.pop();
                for(int i=0; i<6; i++){
                    int val = k+dx[i];
                    if(val > n*n) continue;
                    int rowFromBottom = (val - 1) / n, col = (val - 1) % n;
                    int row = n - 1 - rowFromBottom;
                    if(rowFromBottom % 2 == 1) col = n - 1 - col;
                    int next = board[row][col];
                    if(next!=-1) val = next;
                    if(val == n*n) return moves + 1;
                    if(visited[val] == -1){
                        visited[val] = 0;
                        q.push(val);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};