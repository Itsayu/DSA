// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minColour(int N, int M, vector<int> mat[]) {
        // code here
        vector<int>adj[N+1];
        for(int i=0;i<M; i++){
            int x=mat[i][0],y=mat[i][1];
            adj[y].push_back(x);
        }
        int ans=1;
        vector<int>rank(N+1,0);
        for(int i=1;i<=N;i++){
            ans=max(dfs(N+1,i,adj,rank),ans);
        }
        return ans;
        
    }
    int dfs(int n,int node,vector<int>adj[],vector<int>&Rank ){
        if(Rank[node]){
            return Rank[node];
        }
        int rank=0;
        for(int it:adj[node]){
            rank=max(dfs(n,it,adj,Rank),rank);
        }
        return Rank[node]=rank+1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M, x, y;
        cin>>N>>M;
        vector<int> mat[M];
        for(int i = 0;i < M;i++){
            cin>>x>>y;
            mat[i].push_back(x);
            mat[i].push_back(y);
        }
        
        Solution ob;
        cout<<ob.minColour(N, M, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends