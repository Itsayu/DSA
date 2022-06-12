class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        nr=set()
        ayu=i= akt =0
        for j in range(len(nums)):
            akt+=nums[j]
            while nums[j] in nr:
                akt-=nums[i]
                nr.remove(nums[i])
                i+=1
            nr.add(nums[j])
            ayu=max(ayu,akt)
        return ayu