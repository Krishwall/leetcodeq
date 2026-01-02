/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mpp;
        auto temp=head;

        while(temp!=NULL)
        {
           Node* a= new Node(temp->val);
           mpp[temp]=a;
           temp=temp->next;
        }
        temp=head;
        while(temp!=NULL)
        {
            auto copyNode=mpp[temp];
            copyNode->next=mpp[temp->next];
            copyNode->random=mpp[temp->random];
            temp=temp->next;
        }
        return mpp[head];
    }
};