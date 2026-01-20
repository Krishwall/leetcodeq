/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto x=head;
        if(!head || !head->next) return false;
        auto y=head->next;

        while(x!=y && x!=NULL && y!=NULL && y->next!=NULL)
        {
            x=x->next;
            y=y->next->next;
        }

        if(y==NULL || x==NULL || y->next==NULL)
        return false;
        return true;
    }
};