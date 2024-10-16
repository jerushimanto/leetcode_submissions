class Solution:
    def romanToInt(self, s: str) -> int:
        d={"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}
        i=0
        tot=0
        l=True
        while i<len(s)-1:
            if d[s[i]]<d[s[i+1]]:
                tot+=(d[s[i+1]]-d[s[i]])
                if i+3==len(s):
                    tot+=d[s[-1]]
                i+=2
                l=False            
            else:
                tot+=d[s[i]]
                i+=1
                l=True
        if l:
            tot+=d[s[-1]]
        return tot