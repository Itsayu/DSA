class Solution {
public:
    private:
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    void dfs(vector<vector<int>>& grid, int x, int y, queue<pair<int, int>>& qu) {
        int row = grid.size();
        int col = grid[0].size();
        qu.push({x, y});
        grid[x][y] = 2;
        for(int i = 0; i < 4; i++) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if(nx >= 0 && ny >= 0 && nx < row && ny < col && grid[nx][ny] == 1) {
                dfs(grid, nx, ny, qu);
            }
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        queue<pair<int, int>> qu;
        bool found = false;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j, qu);
                    found = true;
                    break;
                }
            }
            if(found) {
                break;
            }
        }
        
        int level = 0;
        
        while(!qu.empty()) {
            int size = qu.size();
            for(int i = 0; i < size; i++) {
                pair<int, int> point = qu.front();
                qu.pop();
                int x = point.first;
                int y = point.second;
                
                for(int i = 0; i < 4; i++) {
                    int nx = x + dirs[i][0];
                    int ny = y + dirs[i][1];
                    if(nx >= 0 && ny >= 0 && nx < row && ny < col) {
                        if(grid[nx][ny] == 1) {
                            return level;
                        }
                        if(grid[nx][ny] == 0) {
                            grid[nx][ny] = 2;
                            qu.push({nx, ny});
                        }
                    }
                }
            }
            level++;
        }
        return -1;  
    }
};