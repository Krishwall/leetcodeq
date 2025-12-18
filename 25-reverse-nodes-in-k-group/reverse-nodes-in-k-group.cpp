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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        return kReverse(head,k);

    }
    ListNode* reverseLinkedList(ListNode* head)
    {   
        auto temp=head ;
        ListNode* front=NULL;ListNode* prev=NULL;
        if(head==NULL || head->next ==NULL)
         return head;
        while(temp!=NULL)
        {
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;

        }
        return prev;
    }
    ListNode* getKthNode(ListNode* temp,int k)
    {
        k-=1;
        while(temp!=NULL && k>0)
        {   
            temp=temp->next;
            k--;
        }
        return temp;

    }

    ListNode* kReverse(ListNode* head,int k)
    {
        auto temp=head;
        ListNode* prevLast=NULL;
        while(temp!=NULL)
        {
            ListNode* kthNode=getKthNode(temp,k);
            if(kthNode==NULL)
            {
                if(prevLast) prevLast->next=temp;  // for linked list of size LESS THAN K prevLast ==NULL
                break;

            }

            
            auto nextNode=kthNode->next;
            kthNode->next=NULL;
            ListNode* newHead=reverseLinkedList(temp);
            if(temp==head)
            head=newHead;
            else
            prevLast->next=newHead;

            prevLast=temp;
            temp=nextNode;
            

        }
        return head;
    }
};