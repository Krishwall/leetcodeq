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
class   Compare
{   public:
    bool operator()(ListNode* a,ListNode* b)
    {
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* dummy =new ListNode();
        auto curr=dummy;
        priority_queue<ListNode*,vector<ListNode*>,Compare> pq;

        for (auto list :lists)
        {   
            if(list!=NULL)
            pq.push(list);
        }
        while(!pq.empty())
        {
            auto smallest=pq.top();
            pq.pop();
            curr->next=smallest;
            curr=curr->next;
            if(smallest->next!=NULL)
            pq.push(smallest->next);
        }
        return dummy->next;
    }
};