class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        for each in ransomNote:
            x = magazine.find(each)
            if x>-1:
                magazine = magazine[:x] + magazine[x+1:]
            else:
                return False
            
        return True