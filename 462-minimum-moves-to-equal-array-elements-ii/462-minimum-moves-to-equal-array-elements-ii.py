class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        nums.sort()
        mid=len(nums)//2
        ayu=0
        for num in nums:
            ayu+=abs(num-nums[mid])
        return ayu