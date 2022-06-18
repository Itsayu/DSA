class WordFilter:

    def __init__(self, words: List[str]):
        self.prefix = defaultdict(set)
        self.suffix = defaultdict(set) 
        seen = set()
        for ind in range(len(words)-1,-1,-1):
            w = words[ind]
            if w not in seen:
                seen.add(w)
                end = min(len(w)+1,11)
                for l in range(1,end):
                    self.prefix[w[:l]].add(ind)
                    self.suffix[w[len(w)-l:]].add(ind)
                
    def f(self, prefix: str, suffix: str) -> int:
        pre_set = self.prefix[prefix]
        suf_set = self.suffix[suffix]
        ans =  pre_set & suf_set
        if ans:
            return max(ans)
        return -1
        


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)