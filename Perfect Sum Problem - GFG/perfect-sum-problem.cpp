//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	const int mod=1e9+7;
	
	int solve(int i, int arr[], int sum, vector<vector<int>>&dp){
	    if (i < 0) {
            if (sum == 0) {
                return 1;
            } else {
                return 0;
            }
        }
        
        if(dp[i][sum]!=-1) return dp[i][sum];
	    
	    int take=0;
	    if(sum>=arr[i]){
	        take=solve(i-1, arr, sum-arr[i], dp);
	    }
	    int ntake=solve(i-1, arr, sum, dp);
	    return dp[i][sum]=(take+ntake)%mod;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n, vector<int>(sum+1, -1));
        return solve(n-1, arr, sum, dp);
	
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends