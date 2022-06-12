// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalCount(string A){
	    // Code here
	    int S = 0, n = A.size();
        for(char c: A)  S += (c-'0');
        vector<vector<int>> dp(A.size()+1, vector<int>(S+1,0));
        for(int s=0; s<=S; s++)   
            dp[n][s] = 1;
        for(int start=n-1; start>=0; start--){
            for(int prev_sum=0; prev_sum<=S; prev_sum++){
                int sum = 0, res = 0;
                for(int i=start;i<n;i++){
                    sum += (A[i]-'0');
                    if(sum >= prev_sum)
                        dp[start][prev_sum] += dp[i+1][sum];
                }
            }
	    }
	    return dp[0][0];
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends