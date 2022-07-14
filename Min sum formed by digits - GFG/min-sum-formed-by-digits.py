
class Solution:
    def minSum(self, arr, n):
        # Your code goes here
        arr.sort(reverse=True)
        akt=1
        nr=1
        ayu=0
        ni=0
        for i in range(n):
            if i%2==0:
                ayu=ayu+akt*arr[i]
                akt=akt*10
            else:
                ni=ni+nr*arr[i]
                nr=nr*10
        return ni+ayu

#{ 
#  Driver Code Starts

import heapq as hq

if __name__ == '__main__':
    T = int(input())

    for tcs in range(T):
        n = int(input())
        arr = [int(x) for x in input().split()]
        ob=Solution()
        print(ob.minSum(arr,n))

# } Driver Code Ends