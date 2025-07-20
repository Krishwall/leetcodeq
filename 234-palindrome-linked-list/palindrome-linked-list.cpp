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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        auto slow=head;
        auto fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* newHead=reverse(slow->next);
        auto first=head;
        auto second=newHead;

        while(second!=NULL)
        {
            if(first->val!=second->val)
            return false;
            else{
                first=first->next;
                second=second->next;
            }
        }
        return true;
    }

    inline ListNode* reverse(ListNode* head)
    {
        if(head==NULL || head->next==NULL) return head;
        ListNode* newHead=reverse(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newHead;
    }
};