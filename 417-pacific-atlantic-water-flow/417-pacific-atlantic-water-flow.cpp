class Solution {
public:
    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int sr, int sc){
        int horizontal[] = {-1, 0, 1, 0};
        int vertical[] = {0, 1, 0, -1};
        int m = heights.size();
        int n = heights[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            q.push({i, sr});
            ocean[i][sr] = true;
        }
        for(int i=0; i<n; i++){
            if (!ocean[sc][i]){
                q.push({sc, i});
                ocean[sc][i] = true;
            }
        }
        while(!q.empty()){
            pair<int, int> curr = q.front();
            q.pop();
            int curR = curr.first;
            int curC = curr.second;
            for(int i=0; i<4; i++){
                int r = curR + horizontal[i];
                int c = curC + vertical[i];
                if (r>= 0 && r<m && c>=0 && c<n && !ocean[r][c] && heights[curR][curC] <= heights[r][c]){
                    ocean[r][c] = true;
                    q.push({r, c});
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> output;
        if (m == 1 && n == 1){
            output.push_back({0, 0});
            return output;
        }
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        bfs(heights, pacific, 0, 0);
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        bfs(heights, atlantic, n-1, m-1);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if (pacific[i][j] && atlantic[i][j]){
                    output.push_back({i, j});
                }
            }
        }
        return output; 
    }
};