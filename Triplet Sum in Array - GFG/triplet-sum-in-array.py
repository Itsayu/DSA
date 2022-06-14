#User function Template for python3
class Solution:
     
    #Function to find if there exists a triplet in the 
    #array A[] which sums up to X.
    def find3Numbers(self,A, n, X):
        # Your Code Here
        # for i in range(n):
        #   for j in range(i+1,n):
        #       for k in range(j+1,n):
        #           if(A[i]+A[j]+A[k]==X):
        #               return 1
        # return 0
        
        for i in range(n-2):
            sum_dict = {}
            for j in range(i+1, n):
                if X-A[j] in sum_dict:
                    return 1
                sm = A[i] + A[j]
                sum_dict[sm] = j
        return 0
#{ 
#  Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        n,X=map(int,input().strip().split())
        A=list(map(int,input().strip().split()))
        ob=Solution()
        if(ob.find3Numbers(A,n,X)):
            print(1)
        else:
            print(0)
# } Driver Code Ends