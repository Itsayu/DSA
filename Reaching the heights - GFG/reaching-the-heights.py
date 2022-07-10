#User function Template for python3

def reaching_height (n, arr) : 
    #Complete the function
    arr.sort()
    l,r=0,n-1
    ayu=[]
    while l<r:
        ayu.append(arr[r])
        ayu.append(arr[l])
        l+=1
        r-=1
    if n%2:
        ayu.append(arr[l])
    if n>=2:
        if ayu[0]<=ayu[1]:
            return [-1]
    return ayu
#{ 
#  Driver Code Starts
#Initial Template for Python 3


for _ in range(0,int(input())):
    n = int(input())
    arr = list(map(int, input().strip().split()))
    ans = reaching_height(n, arr)
    if(len(ans) == 1 and ans[0] == -1):
        print("Not Possible")
    else:
        print(*ans)
# } Driver Code Ends