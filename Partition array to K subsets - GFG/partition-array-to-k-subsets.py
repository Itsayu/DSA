#User function Template for python3

class Solution:
    def isKPartitionPossible(self, a, k):
        #code here
        s = sum(a)
        if s % k != 0:
            return False
        ayu=s//k
        nr=set()
        def dfs(i, g, s):
            if g == k:
                return True
            if s > ayu:
                return False
            if s==ayu:
                return dfs(0, g+1, 0)
            for j in range(i, len(a)):
                if j in nr:
                    continue
                nr.add(j)
                if dfs(i+1, g, s+a[j]):
                    return True
                nr.remove(j)
            return False
        return dfs(0, 0, 0)
#{ 
#  Driver Code Starts


if __name__ == '__main__':
    tcs = int(input())
    for _ in range(tcs):
        N=int(input())
        arr=[int(x) for x in input().split()]
        k=int(input())
        if Solution().isKPartitionPossible(arr, k):
            print(1)
        else:
            print(0)
# } Driver Code Ends