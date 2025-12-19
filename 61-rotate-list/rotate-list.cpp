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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        int n=1;
        auto temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
            n++;
        }
        temp->next=head;
        k=k%n;
        int kl=0;temp=head;
        while(n-k-1>kl)
        {
            temp=temp->next;
            kl++;
        }
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};