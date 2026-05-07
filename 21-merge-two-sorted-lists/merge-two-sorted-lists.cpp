/**
 * Definition for singly-linked list.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* head=list1->val<list2->val?list1:list2;
        ListNode* curr=new ListNode(0);
        
        while(list1!=nullptr && list2!=nullptr)
        {
            if(list1 && list2 && list1->val<list2->val)
            {   
                curr->next=list1;
                curr=list1;
                list1=list1->next;
            }
            

            else if (list1 && list2 && list1->val>=list2->val)
            {   
                curr->next=list2;
                curr=list2;
                list2=list2->next;
            }
            

        }
        if(!list1)
            curr->next=list2;
        else 
            curr->next=list1;
        return head;
    }
};