//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<int> dist (N, 1e8);
        dist[0] = 0;
        
        for(int i=0; i<M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int cost = edges[i][2];
            if(dist[v] > cost + dist[u]){
                dist[v] = cost + dist[u];
            }
        }
        for(int val = 0; val < dist.size(); val++){
            if(dist[val] == 1e8){
                dist[val] = -1;
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends