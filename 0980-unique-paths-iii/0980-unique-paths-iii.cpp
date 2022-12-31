class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int need = 0;
        int sx = -1;
        int sy = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != -1) {
                    int id = i * m + j;
                    need |= (1 << id);
                }
                if (grid[i][j] == 1) {
                    sx = i;
                    sy = j;
                }
            }
        }
        const vector<pair<int, int>> DIR = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int ans = 0;
        function<void(int, int, int)> dfs = [&](int x, int y, int mask) {
            int id = x * m + y;
            int cmask = mask | (1 << id);
            if (grid[x][y] == 2) {
                if (cmask == need) {
                    ans++;
                }
                return;
            }
            for (auto [dx, dy] : DIR) {
                int cx = x + dx;
                int cy = y + dy;
                if (cx < 0 || cx >= n || cy < 0 || cy >= m) {
                    continue;
                }
                if (grid[cx][cy] == -1) {
                    continue;
                }
                int cid = cx * m + cy;
                if (cmask & (1 << cid)) {
                    continue;
                }
                dfs(cx, cy, cmask);
            }
        };
        dfs(sx, sy, 0);
        return ans;    
    }
};