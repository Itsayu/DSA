#User function template for Python 3

class Solution:
    def majorityElement(self, A, N):
        #Your code here
        A.sort()
        # return A[N-1]
        ayu=A[N//2]
        if(A.count(ayu)>N/2):
            return ayu
        else:
            return -1

#{ 
#  Driver Code Starts
#Initial Template for Python 3

import math

from sys import stdin


def main():
        T=int(input())
        while(T>0):
            
            N=int(input())

            A=[int(x) for x in input().strip().split()]
            
            
            obj = Solution()
            print(obj.majorityElement(A,N))
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends