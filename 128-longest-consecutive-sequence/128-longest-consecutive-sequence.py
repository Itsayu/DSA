class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        values=set()
        for num in nums:
            values.add(num)
        max_count=1
        for i in values:
            if i-1 in values:
                continue
            i+=1
            count=1
            while(i in values):
                count+=1
                i+=1
            max_count=max(max_count,count)
        return max_count
    
        # ayu=0
        # for num in nums:
        #     current_num = num
        #     current_streak = 1
        #     while current_num + 1 in nums:
        #         current_num+=1
        #         current_streak+=1
        #     ayu= max(ayu, current_streak)
        # return ayu