class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        preQ=[0]*(len(arr)+1)
        result=[]
        for i in range(len(arr)):
            preQ[i+1]=preQ[i]^arr[i]

        for l,r in queries:
            result.append(preQ[r+1]^preQ[l])
        return result   
            