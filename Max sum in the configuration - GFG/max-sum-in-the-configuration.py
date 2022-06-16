#User function Template for python3

def max_sum(a,n):
    #code here
    ayu=0
    for i in range(n):
        ayu+=a[i]*i
    nr=sum(a)
    ans=ayu
    for i in range(n):
        ayu+=nr-n*(a[n-i-1])
        if ayu>ans:
            ans=ayu
    return ans
#{ 
#  Driver Code Starts
#Initial Template for Python 3


    
if __name__=='__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        print(max_sum(arr,n))
# } Driver Code Ends