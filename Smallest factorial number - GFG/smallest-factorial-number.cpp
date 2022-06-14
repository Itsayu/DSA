// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        int solve(int n){
            if(n<=1)
                return n;
            return n+solve(n/5);
            }
        int findNum(int n){
            int l=1,r=n;
            while(l<r){
                int mid=(l+r)/2,x=solve(mid);
                if(x>=n)
                    r=mid;
                else
                    l=mid+1;
            }
            return 5*l;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends