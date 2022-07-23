from sortedcontainers import SortedList
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        ayu=[]
        nr=SortedList(nums)
        for i in nums:
            idx=nr.index(i)
            ayu.append(idx)
            nr.remove(i)
        return ayu