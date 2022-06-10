// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxCoins(int A[], int B[], int T, int N) {
        // code here
        vector<pair<int,int>>B_A(N);
        for(int i=0;i<N;i++){
            B_A[i]={B[i],A[i]};
        }
        sort(B_A.rbegin(),B_A.rend());
        int ans=0;
        int cur=0;
        while(T && cur<N){
            while(T && B_A[cur].second)
                ans+=B_A[cur].first ,T--,B_A[cur].second--;
                cur++ ;
        }
        return ans ;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends