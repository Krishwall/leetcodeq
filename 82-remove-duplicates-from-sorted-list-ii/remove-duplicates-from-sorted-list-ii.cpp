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
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy=new ListNode();
        dummy->next=head;
        head=dummy;
        auto x=dummy;
        ListNode* y=x->next;

        while(y!=NULL && y->next!=NULL){
            if(y->next!=NULL && y->next->val==y->val )
            {while(y->next!=NULL && y->next->val==y->val)
                {
                    y=y->next;
                }
            x->next=y->next;
            }

            else
            {
                x=x->next;
            }
            y=y->next;
            

        }
        return head->next;

        
    }
};