class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        nums.sort()
        if len(nums)==1:
            return 0
        else:
            ayu=0
        for i in range(len(nums)-1):
            if nums[(i+1)]-nums[i]>ayu:
                ayu=nums[(i+1)]-nums[i]
        return ayu