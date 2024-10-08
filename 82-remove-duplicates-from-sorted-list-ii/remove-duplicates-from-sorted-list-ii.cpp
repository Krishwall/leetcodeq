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
        if (!head || head->next==nullptr)
            return head;
        auto dummy=new ListNode(0);
        dummy->next=head;
        auto curr=head;
        auto prev=dummy;

        while (curr)
        {
            while (curr->next && curr->val==curr->next->val)
                curr=curr->next;

            if (prev->next==curr)
                {prev=prev->next;
                curr=curr->next;
                }
            else
                {
                    prev->next=curr->next;
                    curr=prev->next;
                }
        }
        return dummy->next;
    }
};