class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j]!=1) return ;
        grid[i][j] = 0;
        int x[] = {-1,1,0,0}, y[] = {0,0,-1,1};
        for(int a=0;a<4;a++){
            dfs(grid, i+x[a], j+y[a]);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int res = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i*j==0 or i==grid.size()-1 or j==grid[0].size()-1)
                    dfs(grid,i,j);
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                res += grid[i][j];
            }
        }
        return res;  
    }
};