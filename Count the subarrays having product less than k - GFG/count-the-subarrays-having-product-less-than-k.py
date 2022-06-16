#User function Template for python3

class Solution:
    def countSubArrayProductLessThanK(self, a, n, k):
        #Code here
        akt=1
        nr=0
        ayu=0
        for i in range(n):
            akt*=a[i]
            while nr<i and akt>k:
                akt//=a[nr]
                nr+=1
            if akt<k:
                ayu+=i-nr+1
        return ayu
#{ 
#  Driver Code Starts
#Initial Template for Python 3

def main():

    T = int(input())

    while(T > 0):
        n, k = [int(x) for x in input().strip().split()]
        arr = [int(x) for x in input().strip().split()]
        
        print(Solution().countSubArrayProductLessThanK(arr, n, k))

        T -= 1


if __name__ == "__main__":
    main()


# } Driver Code Ends