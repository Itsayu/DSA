class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min=prices[0]
        ayu=0
        for i in prices[1:]:
            if i<min:
                min=i
            elif (i-min)>ayu:
                 ayu=i-min
        return ayu