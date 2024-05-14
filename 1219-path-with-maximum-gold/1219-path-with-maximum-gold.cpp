class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
		int m = grid[0].size();
		int ans = 0;

		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				if(grid[i][j] != 0){
					 ans = max(ans, solve(grid, i, j, n, m));
				}
			}
		}
		return ans;
    }

    int solve(vector<vector<int>>& grid, int i, int j, int n, int m){

		int ans = 0, temp = 0;

		if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == 0){
			return 0;
		}

		temp = grid[i][j];
		grid[i][j] = 0;

		ans = max(ans, solve(grid, i-1, j, n, m));
		ans = max(ans, solve(grid, i+1, j, n, m));
		ans = max(ans, solve(grid, i, j-1, n, m));
		ans = max(ans, solve(grid, i, j+1, n, m));

		grid[i][j] = temp;

		return ans + temp;
	}
};