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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (!(head) || (left==right)) 
            return head;
        ListNode* dummy=new ListNode(0);
        dummy->next =head;
        ListNode* prev=dummy;

        for(auto i=0;i<left-1;++i){
            prev=prev->next;

        }
        ListNode* curr;
        curr=prev->next;
        ListNode* next_node;
        for(int i=0;i<right-left;++i)
        {   
            next_node= curr->next;
            curr->next=next_node->next;
            next_node->next=prev->next;
            prev->next=next_node;

        }
        return dummy->next;

    }
};