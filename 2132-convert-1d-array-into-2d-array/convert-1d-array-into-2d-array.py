import numpy as np
class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        if m*n!=len(original):
            return []
        
        result=[]
        a=[]
        for i in range(m*n):
            if (i+1)%n==0:
                a.append(original[i])
                result.append(a)
                a=[]
            else: 
                a.append(original[i])
        return result
           
            