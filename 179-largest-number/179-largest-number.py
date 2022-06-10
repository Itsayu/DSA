class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        if len(nums)==1:
            return str(nums[0])
        
        for i in range(len(nums)):
            nums[i]=str(nums[i])
        
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                if nums[j]+nums[i]>nums[i]+nums[j]:
                    nums[i],nums[j]=nums[j],nums[i]
        result="".join(nums)
        if result==("0"*len(result)):
            return "0"
        else:
            return result