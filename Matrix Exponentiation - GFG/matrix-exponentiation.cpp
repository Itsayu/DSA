// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
typedef vector<vector<long long> > matrix;
typedef long long ll;
const int M = 1e9+7;
class 
Solution {
public:
    matrix mulMat(matrix a,matrix b){
	    matrix ans(2, vector<long long>(2, 0));
	    int size = a.size();
	    for (int i = 0; i < a.size(); ++i){
		    for(int j =0;j<b.size();j++){
			    for(int k =0;k<b.size();k++){
			       	ans[i][j] = (ans[i][j] + a[i][k]*b[k][j])%M;
			    }
		    }
	    }
	    return ans;
    }
    matrix matExp(matrix poweredBase,ll n){
	    if(n==1)
	        return poweredBase;
	    ll half=n/2;
	    matrix ans(2, vector<long long>(2, 0));
	    ans=matExp(poweredBase,half);
	    ans=mulMat(ans,ans);
	    if(n%2==0){
		    return ans;
	    }
	    else {
		    ans=mulMat(ans,poweredBase);
		    return ans;
	    }
    }
    int FindNthTerm(long long int n) {
        // Code here
        if(n==0) return 1;
	if(n==1) return 1;
	matrix base(2, vector<long long>(2, 0));
	base[0][0]=1;
	base[0][1]=1;
	base[1][0]=1;
	base[1][1]=0;
	matrix initial(2, vector<long long>(1, 0));
	initial[0][0]=initial[1][0] = 1;
    matrix poweredBase=matExp(base,n-1);
    matrix result=mulMat(poweredBase,initial);
	return result[0][0];
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int n;
		cin >> n;
		Solution obj;
		int ans = obj.FindNthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends