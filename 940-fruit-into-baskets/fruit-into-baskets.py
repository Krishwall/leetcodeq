class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        a=set()
        left=0
        maxcount=0
        count=0
        while left<len(fruits):
            if len(a)==2:
                
                if fruits[left] in a:

                    count+=1
                elif fruits[left] not in a:
                    a.add(fruits[left])
                    first=fruits[left-1]
                    right=left
                    left-=1
                    count=0
                    while fruits[left] ==first:
                        count+=1
                        left-=1
                    count+=1
                    a.remove(fruits[left])
                    left=right
            else:
                a.add(fruits[left])
                count+=1
            left+=1
            maxcount=max(maxcount,count)
        return maxcount
                    
                
