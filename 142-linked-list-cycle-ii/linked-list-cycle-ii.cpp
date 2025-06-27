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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* node=head;

        while(fast && fast->next)
        {
            node=node->next;
            fast=fast->next->next;

            if(node==fast) {
                node=head;
                while(node!=fast)
                {
                    node=node->next;
                    fast=fast->next;
                }
                delete fast;
                return node;
            }
        }
       
        
        return NULL;
    }
};