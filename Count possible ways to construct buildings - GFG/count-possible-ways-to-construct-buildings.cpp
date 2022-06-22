// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    int M = 1e9+7;
	public:
	int TotalWays(int N)
	{
	    // Code here
	    if(!N)
	        return 1;
	    if(N==1)
	        return 4;
	    int a=1,b=2;
	    long long int ans;
	    for(int i=2;i<=N;i++)
	        ans=(a+b)%M,a=b,b=ans;
	    return (ans*ans)%M;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends