class Solution:
    def threeSumMulti(self, arr: List[int], target: int) -> int:
        n=len(arr)
        ayu=0
        nums=Counter(arr[:1])
        for i in range(1,n-1):
            for j in range(i+1,n):
                ayu= (ayu+nums[target-arr[j]-arr[i]])%1000000007  
            nums[arr[i]]+=1
        return ayu