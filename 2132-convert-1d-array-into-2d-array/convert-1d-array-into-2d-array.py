import numpy as np
class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        if m*n!=len(original):
            return []
        
        result=[]
        k=0
        for i in range(m):
            a=[]
            for j in range(n):
                a.append(original[k])
                k+=1
            result.append(a)

            
        return result
           
            