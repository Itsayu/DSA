class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        heads = defaultdict(list)
        for word in words:
            heads[word[0]].append(word)
        ayu=0
        for c in s:
            strs=heads[c]
            heads[c]=[]
            for part in strs:
                if len(part)==1:
                    ayu+=1
                else:
                    heads[part[1]].append(part[1:])
        return ayu