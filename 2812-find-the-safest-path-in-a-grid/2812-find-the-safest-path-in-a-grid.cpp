class Solution {
public:
    vector<int> xd = {1, -1, 0, 0};
    vector<int> yd = {0, 0, -1, 1};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<vector<int>> distance(n, vector<int>(n, -1));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j]) {
                    q.push({i, j});
                    distance[i][j] = 0;
                }
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int nx = x + xd[k], ny = y + yd[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && distance[nx][ny] == -1) {
                    distance[nx][ny] = distance[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        priority_queue<array<int, 3>> djk;
        djk.push({distance[0][0], 0, 0});
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        while (!djk.empty()) {
            auto [safe, x, y] = djk.top();
            djk.pop();
            if (x == n - 1 && y == n - 1) return safe;
            if (visited[x][y]) continue;
            visited[x][y] = true;
            for (int k = 0; k < 4; ++k) {
                int nx = x + xd[k], ny = y + yd[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                    djk.push({min(safe, distance[nx][ny]), nx, ny});
                }
            }
        }
        
        return -1;
    }
};