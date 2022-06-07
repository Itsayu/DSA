// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        if(n==1){
            return 0;
            }
        int akt;
        int steps=1;
        int ayu=0;
        for(int i=0;i<=akt;i++){
            akt=max(akt,i+arr[i]);
            if(akt>=n-1){
                return ayu+1;
            }
            steps--;
            
            if(!steps){ 
                ayu++;
                steps=akt-i;
            }
        }
        
        return -1;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends