// https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    int count = 0;

    void dfs(vector<vector<char>> &grid, int m, int n, vector<vector<int>> &visited, 
                vector<int> &dx, vector<int> &dy, int i, int j){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == '0' || visited[i][j] == 0) return;
        visited[i][j] = 0;
        for(int k=0; k<4; k++){
            int newRow = i+dx[k], newCol = j+dy[k];
            if(newRow >=0 && newRow < m && newCol >=0 && newCol < n && grid[newRow][newCol] == '1' && visited[newRow][newCol] == -1){
                dfs(grid, m, n, visited, dx, dy, newRow, newCol);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int> (n, -1));
        vector<int> dx = {0, +1, 0, -1};
        vector<int> dy = {+1, 0, -1, 0};
        for(int i=0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == '1' && visited[i][j] == -1){
                    count++;
                    dfs(grid, m, n, visited, dx, dy, i, j);
                }
            }
        }
        return count;
    }
};