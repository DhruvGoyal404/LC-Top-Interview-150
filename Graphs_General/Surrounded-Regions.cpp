// https://leetcode.com/problems/surrounded-regions/
class Solution {
public:
    void solve(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        vector<int> dx = {0, +1, 0, -1};
        vector<int> dy = {+1, 0, -1, 0};
        vector<vector<int>> visited(n, vector<int> (m , -1));
        for(int i=0; i<n; i++){
            if(grid[i][0] == 'O' && visited[i][0] == -1){
                visited[i][0] = 0;
                q.push({i, 0});
            }
            if(grid[i][m-1] == 'O' && visited[i][m-1] == -1){
                visited[i][m-1] = 0;
                q.push({i, m-1});
            }
        }

        for(int j=0; j<m; j++){
            if(grid[0][j] == 'O' && visited[0][j] == -1){
                visited[0][j] = 0;
                q.push({0, j});
            }
            if(grid[n-1][j] == 'O' && visited[n-1][j] == -1){
                visited[n-1][j] = 0;
                q.push({n-1, j});
            }
        }

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int newRow = it.first+dx[i], newCol = it.second + dy[i];
                if(newRow >= 0 && newRow < n && newCol >=0 && newCol < m && grid[newRow][newCol] == 'O' && visited[newRow][newCol] == -1){
                    visited[newRow][newCol] = 0;
                    q.push({newRow, newCol});
                }
            }
        }

        for(int i=0; i<n-1; i++) for(int j=0; j<m-1; j++) if(grid[i][j] == 'O' && visited[i][j] == -1) grid[i][j] = 'X';
    }
};