class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
    
        mul = set()
        for num in arr:
            if num * 2 in mul or num / 2 in mul:
                return True
            mul.add(num)
        return False

