class Solution {
public:
    int dp[101][101];
	int solve(vector<vector<int>>& mat,int i,int j){
		if(i==mat.size()) return 0;
		if(j>=mat.size() || j<0) return 1e9;
		if(dp[i][j]!=-1) return dp[i][j];
		int tot=INT_MAX;
		tot = min(tot,mat[i][j]+solve(mat,i+1,j-1));
		tot = min(tot,mat[i][j]+solve(mat,i+1,j));
		tot = min(tot,mat[i][j] + solve(mat,i+1,j+1));
		return dp[i][j]=tot;
	}
	int minFallingPathSum(vector<vector<int>>& mat) {
		int n = size(mat);
		memset(dp,-1,sizeof(dp));
		int ans=INT_MAX;
		for(int j=0;j<n;j++) ans=min(ans,solve(mat,0,j));
		return ans;
    }
};