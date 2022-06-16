class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for c in s:
            if(c=='[' or c=='(' or c=='{'):
                stack.append(c)
            elif(len(stack)==0):
                return False
            elif(c==')' and stack[-1]=='('):
                stack.pop()
            elif(c==']' and stack[-1]=='['):
                stack.pop()
            elif(c=='}' and stack[-1]=='{'):
                stack.pop()
            else:
                return False
        return len(stack)==0