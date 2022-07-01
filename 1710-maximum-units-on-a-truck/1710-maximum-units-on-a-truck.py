class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key= lambda x:x[1], reverse=True)
        Total=0
        while truckSize>0 and boxTypes:
            boxType=boxTypes.pop(0)
            if boxType[0]<=truckSize:
                Total+=boxType[0]*boxType[1]
                truckSize-=boxType[0]
            else:
                Total+=truckSize*boxType[1]
                truckSize=0
        return Total