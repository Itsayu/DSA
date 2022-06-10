class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        ayu={}
        for i in nums:
            if i not in ayu:
                ayu[i] = 0
            ayu[i] += 1
            if ayu[i] > len(nums) // 2:
                return i