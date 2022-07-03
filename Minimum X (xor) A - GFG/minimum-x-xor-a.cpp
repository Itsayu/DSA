// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int c=0;
        while(b>0){
            b=b&(b-1);
            c++;
        }
        int x=0;
        int i=log2(a);
        while(c>0 && i>=0){
            if(a&(1<<i)){
                c--;
                x=x|(1<<i);
            }
            i--;
        }
        i=0;
        while(c>0){
            if(!(x&(1<<i))){
                c--;
                x=x|(1<<i);
            }
            i++;
        }
        return x;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends