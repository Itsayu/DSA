// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        //code here.
        unordered_map<int,int>mp1,mp2;
        int count=0;
        for(int i=0;i<n;i++){
            mp1[arr[i]]++;
        }
        int k=mp1.size();
        int i=-1;
        int j=-1;
        while(true){
            bool f1=false;
            bool f2=false;
            while(i<n-1){
                f1=true;
                i++;
                mp2[arr[i]]++;
                if(mp2.size()==k){
                    count+=n-i;
                    break;
                }
            }
            while(j<i){
                f2=false;
                j++;
                if(mp2[arr[j]]==1){
                    mp2.erase(arr[j]);
                }
                else{
                    mp2[arr[j]]--;
                }
               
                if(mp2.size()==k){
                    count+=n-i;
                }
                else{
                    break;
                }
               
            }
            if(f1==false && f2==false){
                break;
            }
        }
        return count;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends