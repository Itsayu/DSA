//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        int ans = 0;
        for(int i=0; i<s.length(); i++){
            vector<int> nr(26, 0);
            for(int j=i; j<s.length(); j++){
                nr[s[j] - 'a']++;
                int max_f = 0, min_f = INT_MAX;
                for(auto x: nr){
                    max_f = max(max_f, x);
                    if(x >= 1) min_f = min(min_f, x);
                }
                ans += (max_f - min_f);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends