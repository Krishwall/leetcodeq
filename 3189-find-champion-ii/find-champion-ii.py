class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        arr=[0]*n
        for vertex in edges:
            arr[vertex[1]]=1
        if arr.count(0)>1:
            return -1
        else :
            return arr.index(0)
