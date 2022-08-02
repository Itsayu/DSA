class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        ayu=[]
        for i in range(len(matrix)):
            ayu+=matrix[i][0:]
        ayu.sort()
        return ayu[k-1]