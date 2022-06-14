#User function Template for python3

def chocolates (arr, n) : 
    #Complete the function
    arr.sort()
    return arr[0]


#{ 
#  Driver Code Starts
#Initial Template for Python 3


for _ in range(0,int(input())):
    n = int(input())
    arr = list(map(int, input().strip().split()))
    ans = chocolates(arr, n)
    print(ans)
    





# } Driver Code Ends