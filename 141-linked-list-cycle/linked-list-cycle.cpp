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
        if(!head || !head->next) return false;
        auto x=head;
        auto y=head;

        while(y!=NULL && y->next!=NULL)
        {
            x=x->next;
            y=y->next->next;

            if(x==y)return true;
        }

        return false;
        
    }
};