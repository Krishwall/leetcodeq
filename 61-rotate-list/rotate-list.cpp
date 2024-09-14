/**
 * Definition for singly-linked list->
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (!head)
            return nullptr;
        if (k==0)
            return head;
        auto endElement=head;
        int length=1;
        while (endElement->next){
            endElement=endElement->next;
            length+=1;
        }

        if (length<2 or k%length==0)
            return head;
        endElement->next=head;

        k%=length;
        auto tempNode=head;

        for(auto i=0;i<length-k-1;++i){
            tempNode=tempNode->next;
        }
        auto shiftk=tempNode->next;
        tempNode->next=nullptr;
        
        return shiftk;
    }
};