// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
        int ans = -1;
        int m[12][12];
        void trvs(vector<vector<int>> matrix,int xd, int yd,int i,int j,int count){
            if(i<0||i>=matrix.size()||j>=matrix[0].size()||j<0||matrix[i][j]==0||m[i][j]==1){return;}
            m[i][j]=1;
            if(i==xd && j==yd){
                ans=max(ans,count);
                m[i][j]=0;
                return; 
            }
            trvs(matrix,xd,yd,i-1,j,count+1);
            trvs(matrix,xd,yd,i+1,j,count+1);
            trvs(matrix,xd,yd,i,j-1,count+1);
            trvs(matrix,xd,yd,i,j+1,count+1);
            m[i][j]=0;
             return;
        }
        int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd){
            memset(m,0,sizeof(m));
            trvs(matrix,xd,yd,xs,ys,0);
            return ans;
        }
};
// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends