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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return nullptr;
        ListNode* shead=new ListNode(0);
        ListNode* bhead=new ListNode(0);
        ListNode* s=shead;
        ListNode* b=bhead;
        while(head){
            ListNode* n=head->next;
            head->next=nullptr;
            if(head->val>=x){
                bhead->next=head;
                bhead=bhead->next;
            }
            else{
                shead->next=head;
                shead=shead->next;
            }
            head=n;
        }
        bhead->next=nullptr;
        shead->next=b->next;
        return s->next;
    }
};