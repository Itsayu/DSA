class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        horizontalCuts=[0]+sorted(horizontalCuts)+[h]
        verticalCuts=[0]+sorted(verticalCuts)+[w]
        horizontalCuts= max(horizontalCuts[i+1]-horizontalCuts[i] for i in range(len(horizontalCuts)-1))
        wmax = max(verticalCuts[i+1]-verticalCuts[i] for i in range(len(verticalCuts)-1))
        return (horizontalCuts*wmax) % (10**9 + 7)