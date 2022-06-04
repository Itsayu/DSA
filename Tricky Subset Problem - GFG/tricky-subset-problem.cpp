// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isPossible(long long S, long long N, long long X, long long A[])
    {
        vector<long long>v;
        v.push_back(S);
        long long ayu = S;
        for(long long i=0; i<N;i++){
            long long temp=ayu + A[i];
            v.push_back(temp);
            if(temp>=X)
            break;
            ayu+=temp;
        }
        long long i= v.size() -1;
        while(i>=0 && X>0){
            if(X>=v[i]){
                X-=v[i];
                
            }
            i--;
        }
        if(X==0)
        return 1;
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long S, N, X;
        cin>>S>>N>>X;
        long long A[N];
        for(long long i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        if(ob.isPossible(S, N, X, A))
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}  // } Driver Code Ends