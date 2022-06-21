#User function Template for python3

class Solution:
    def minValue(self, a, b, n):
        # Your code goes here
        ayu=0
        a.sort()
        b.sort()
        for i in range(0,n):
            ayu+=a[i]*b[i]
        return ayu


#{ 
#  Driver Code Starts
#Initial Template for Python 3


def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        b = [int(x) for x in input().strip().split()]
        ob=Solution()
        print(ob.minValue(a, b, n))

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends