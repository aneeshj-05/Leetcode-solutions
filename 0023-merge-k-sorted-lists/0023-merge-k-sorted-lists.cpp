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
    struct cmp{
        bool operator()(ListNode* a,ListNode* b){ return a->val>b->val; }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        for(auto l:lists){
            while(l){
                pq.push(l);
                l=l->next;
            }
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* trail=dummy;
        while(!pq.empty()){
            ListNode* t=pq.top();
            pq.pop();
            trail->next=t;
            trail=trail->next;
        }
        trail->next=nullptr;
        return dummy->next;
    }
};