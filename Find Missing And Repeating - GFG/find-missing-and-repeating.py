#User function Template for python3

class Solution:
    def findTwoElement( self,arr, n): 
        # code here
        n=len(arr)
        for i in range(n):
            x=arr[i]%(n+1)
            arr[x-1]+=n+1
        ayu=[None,None]
        for i in range(n):
            if arr[i]//(n+1)>1:
                ayu[0]=i+1
            if arr[i]//(n+1)<1:
                ayu[1]=i+1
        return ayu 
#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 

    tc=int(input())
    while tc > 0:
        n=int(input())
        arr=list(map(int, input().strip().split()))
        ob = Solution()
        ans=ob.findTwoElement(arr, n)
        print(str(ans[0])+" "+str(ans[1]))
        tc=tc-1
# } Driver Code Ends