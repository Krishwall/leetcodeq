class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        if len(original) != n*m:
            return []
        o = []
        i = 0
        while i < len(original):
            o.append(original[i:i+n])
            i+=n
        return o