// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
       int low=0;
       int mid=0;
       int high=n-1;
       while(mid<=high){
           if(a[mid]==0){
               int temp=a[low];
               a[low]=a[mid];
               a[mid]=temp;
               low++;
               mid++;
           }
           else if (a[mid]==2){
               int temp=a[high];
               a[high]=a[mid];
               a[mid]=temp;
               high--;
           }
           else mid++;
       }
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends