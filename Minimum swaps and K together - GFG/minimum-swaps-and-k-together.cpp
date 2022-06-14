// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        int count=0;
        for(int i=0; i<n; i++){
            if(arr[i]<=k){
                count++;
            }
        }
    int max=0, total=count;
    int i=0,j=0;
    for(int i=0; i<count; i++){
        if(arr[i]>k){
            max++;
        }
    }
    total=max;
 
    j=count-1;
    i++;
    j++;
    for(; i<=n-count; ){
        if(arr[i-1]>k)
            max--;
        if(arr[j]>k)
            max++;
        if(max<total) {
            total=max;
            
        }
        i++;
        j++;
         
    }
    return total;
    }
};


// { Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
  // } Driver Code Ends