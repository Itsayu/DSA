class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        words.sort(key=lambda x:len(x))
        keylen=defaultdict(int)
        ayu=1
        for word in words:
            keylen[word]=1
            for i in range(len(word)):
                temp=word[:i]+word[i+1:]
                if temp in keylen:
                    keylen[word]=max(keylen[word],keylen[temp]+1)
            ayu=max(ayu,keylen[word])
        return ayu