#User function Template for python3

class Solution:
    def MedianOfArrays(self, array1, array2):
            #code here
            ayu=list(array1+array2) 
            ayu.sort() 
            if len(ayu)%2==0: 
                nr=ayu[len(ayu)//2]+ayu[len(ayu)//2-1]
                if nr%2==0:
                    return nr//2
                else:
                    return nr/2
            else:
               return ayu[len(ayu)//2]
#{ 
#  Driver Code Starts
if __name__ == '__main__':
    tcs=int(input())

    for _ in range(tcs):
        m = input()
        arr1=[int(x) for x in input().split()]
        n = input()
        arr2=[int(x) for x in input().split()]
        
        
        ob = Solution()
        print(ob.MedianOfArrays(arr1,arr2))

# } Driver Code Ends