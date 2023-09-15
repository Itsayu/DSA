//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int N)
    {
        // your code here
        vector<long long>dp(N+3,0);
        dp[1]=1;
        dp[2]=2;
        dp[3]=4;
        if(N<=3){
            return dp[N];
        }
        int MOD=1e9+7;
        for(int i=4;i<N+3;i++){
            dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%MOD;
        }
        return dp[N];
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends