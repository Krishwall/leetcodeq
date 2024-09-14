# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        
        if not head:
            return None
        if(k==0):
            return head
        lastElement=head
        length=1
        while lastElement.next:
            lastElement=lastElement.next
            length+=1
        if(length<2 or k%length == 0):
            return head
        lastElement.next=head

        k%=length
        tempNode=head
        for _ in range(length-k-1):
            tempNode=tempNode.next
        shiftk=tempNode.next
        tempNode.next=None
        
        return shiftk