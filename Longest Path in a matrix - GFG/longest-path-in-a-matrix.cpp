// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(), vector<int>(matrix[0].size(),0));
        int maks=0;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size();j++){
                maks=max(maks, longestPath(matrix,i,j,dp)); 
            }
        }
        return maks;
    }
    int longestPath(vector<vector<int>>&mat, int i, int j, vector<vector<int>>&dp){
        if(i<0 || j<0 || i>=mat.size() || j>mat[0].size())
        return 0;
        if(dp[i][j]>0)
            return dp[i][j];   
        int currMax = 1;

        if(i+1<mat.size() && i+1>=0 && mat[i+1][j]>mat[i][j]){
            currMax=max(currMax, 1+longestPath(mat,i+1,j,dp));
        }
        if(j+1<mat[0].size() && j+1>=0 && mat[i][j+1]>mat[i][j]){
            currMax=max(currMax, 1+longestPath(mat,i,j+1,dp));
        }
        if(j-1<mat[0].size() && j-1>=0 && mat[i][j-1]>mat[i][j]){
            currMax=max(currMax, 1+longestPath(mat,i,j-1,dp));
        }
        if(i-1<mat.size() && i-1>=0 && mat[i-1][j]>mat[i][j]){
            currMax=max(currMax, 1+longestPath(mat,i-1,j,dp));
        }
        dp[i][j] = currMax;
        return currMax;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends