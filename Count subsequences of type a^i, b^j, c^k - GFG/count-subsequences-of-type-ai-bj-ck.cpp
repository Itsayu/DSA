// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        //code here
        int mod=1e9+7;
        int a=0, ab=0, abc=0;
        for(auto& c:s){
            if(c=='a'){
                a=(2*1LL*a+0LL+1)%mod;
            }
            else if(c=='b'){
                ab=(2*1LL*(ab)+0LL+a)%mod;
            }
            else if(c=='c'){
                abc=(2*1LL*(abc)+0LL+ab)%mod;
            }
        }
        return abc;
    }
};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends