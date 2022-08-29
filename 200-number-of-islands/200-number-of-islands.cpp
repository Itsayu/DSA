class Solution {
public:
    void dfs(int i,int j,vector<vector<char>> &grid,vector<vector<int>> &vis){
        vis[i][j]=1;
        
        int m=grid.size(),n=grid[0].size();
        
        if(i<m-1 and grid[i+1][j]=='1' and !vis[i+1][j]) dfs(i+1,j,grid,vis);
        if(i>0 and grid[i-1][j]=='1' and !vis[i-1][j]) dfs(i-1,j,grid,vis);
        if(j<n-1 and grid[i][j+1]=='1' and !vis[i][j+1]) dfs(i,j+1,grid,vis);
        if(j>0 and grid[i][j-1]=='1' and !vis[i][j-1]) dfs(i,j-1,grid,vis);

    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' and !vis[i][j]){
                    dfs(i,j,grid,vis);
                    ++ans;
                }
            }
        }
        return ans;
    }
};