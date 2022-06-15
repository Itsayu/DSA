// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here 
        int n=str.size();
        int uniq=unordered_set<char>(str.begin(), str.end()).size();
        unordered_map<char, int>hm;
        int i=0,j=0;
        int ans=INT_MAX,count=INT_MAX;
        while(j<n){
            hm[str[j++]]++;
            while(hm.size()==uniq){
                count=j-i;
                ans=min(ans,count);
                hm[str[i]]--;
                if(hm[str[i]]==0) 
                	hm.erase(str[i]);
                i++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends