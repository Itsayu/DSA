# function to return maximum XOR subset in set[]

class Solution:
    def maxSubarrayXOR(self, arr, N):
        # add code here
        x=0
        while True:
            y=max(arr)
            if y==0:
                return x
            x=max(x, x^y)
            arr=[min(z,z^y) for z in arr]

#{ 
#  Driver Code Starts
if __name__=='__main__':
    t=int(input())
    for i in range(t):
        n=int(input())
        set=list(map(int,input().split()))
        obj = Solution()
        print(obj.maxSubarrayXOR(set,n))
# } Driver Code Ends