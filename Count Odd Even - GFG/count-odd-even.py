#User function Template for python3

class Solution:
	def countOddEven(self, arr, n):
		#Code here
		odd=0
		even=0
        for i in arr:
            if(i%2==0):
                even+=1
            else:
                odd+=1
        print(odd,even)
#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T=int(input())
    for i in range(T):
        n = int(input())
        arr = list(map(int, input().strip().split()))
    	obj = Solution()
    	obj.countOddEven(arr, n);
# } Driver Code Ends