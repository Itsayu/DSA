#User function Template for python3

class Solution:
    #Complete this function
    # Function to find the maximum index difference.
    def maxIndexDiff(self,A, N): 
        ##Your code here
        ayu=0
        for i in range(0,N-1):
            for j in range(N-1,i,-1):
                if A[i]<=A[j]:
                    ayu=max(ayu,j-i)
                    brea
        return ayu

#{ 
#  Driver Code Starts
#Initial Template for Python 3

import math

def main():
        T=int(input())
        while(T>0):
            
            n=int(input())
            
            arr=[int(x) for x in input().strip().split()]
            ob=Solution()
            print(ob.maxIndexDiff(arr,n))
            
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends