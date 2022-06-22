// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool partitionArray(int N, int K, int M, vector<int> &A){
        // code here
        // bool ayu=true;
        // int count=1;
        // sort(A.begin(),A.end());
        // for (int i=0;i<N;i++){
        //     if (A[i+1]-A[i]<=M and A[i+1]!=A[i]){count+=1;}
        //     else if (A[i+1]-A[i]>M){
        //         if (count<K){
        //             ayu=false;
        //         }
        //         else{
        //             count=1;
        //         }
        //     }
        // }
        // return ayu;
        // ----------------------OR-----------------------
        // sort(A.begin() , A.end());
        // vector<int>dp(N+1,0);
        // dp[N]=1;
        // for(int i=N-1;i>=0;i--){
        //     for(int j=i+K-1;j<N&&A[j]-A[i]<=M;j++){
        //         dp[i]|=dp[j+1];
        //     }
        // }
        // return dp[0];
        // --------------------------OR---------------------------
        bool dp[N+1]={0};
        dp[0]=1;
        sort(A.begin(),A.end());
        for(int i=K;i<=N;i++){
            int l=lower_bound(A.begin(),A.end(),A[i-1]-M)-A.begin();
            int h=i-K;
            for(int j=l;j<=h;j++){
                dp[i]|=dp[j];
                if (dp[i])
                    break;
            }
        }
        return dp[N];
    }
};

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, K, M;
        cin >> N >> K >> M;
        vector<int> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        Solution obj;
        bool ans = obj.partitionArray(N, K, M, A);
        if(ans){
            cout << "YES\n";
        }
        else{
            cout<< "NO\n";
        }
    }
}
  // } Driver Code Ends