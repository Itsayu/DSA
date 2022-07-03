// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    unordered_map<string,vector<string>>dp;
        vector<string> wordBreak(int n, vector<string>& dict, string s){
        // code here
            if(dp.find(s)!=dp.end())
            return dp[s];
            vector<string>ans;
            for(string w:dict){
                if(s.substr(0,w.length())==w){
                    if(w.length()==s.length())
                        ans.push_back(w);
                    else{
                        vector<string>temp=wordBreak(n-1,dict,s.substr(w.length()));
                        for(string t:temp){
                            ans.push_back(w+" "+t);
                        }
                    }
                }
            }
            return dp[s]=ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends