class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator==0: return  "0"
        sign='-' if ((numerator<0) ^ (denominator<0) ) else ''

        n,d,rem_map,ans=abs(numerator),abs(denominator),{},str(abs(numerator)//abs(denominator))

        n=n%d

        if n==0: return sign+ans
        ans,frac,fraccount =ans+'.','',0
        while n not in rem_map and n!=0:
            rem_map[n],n=fraccount,n*10
            frac+=str(n//d)
            n%=d
            fraccount+=1
        if n==0: return sign+ans+frac
        else: return sign+ans+frac[:rem_map[n]]+'('+frac[rem_map[n]:]+')' 
