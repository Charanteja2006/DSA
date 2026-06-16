class Solution:
    def processStr(self, s: str) -> str:
        temp = ""
        for c in s:
            if c>='a' and c<='z':
                temp = temp + c
            elif c=='*':
                l = len(temp)
                if l>0:
                    temp = temp[:-1]
            elif c=='#':
                temp = temp + temp
            elif c=='%':
                temp = temp[::-1]
        return temp

        