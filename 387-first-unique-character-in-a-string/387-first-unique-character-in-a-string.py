class Solution:
    def firstUniqChar(self, s: str) -> int:
        c = collections.Counter(s)
        for idx,val in enumerate(s):
            if(c[val]==1):
                return idx
        return -1