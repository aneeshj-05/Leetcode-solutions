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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int cnt=0;
        ListNode* sh=list1;
        ListNode* dummy=new ListNode(0);
        dummy->next=list1;
        while(list1){
            if(cnt==a){
                dummy->next=list2;
                while(list2->next) list2=list2->next;
                dummy=list1; 
            }
            if(cnt==b){
                list2->next=dummy->next;
                dummy->next=nullptr;
                break;
            }
            list1=list1->next;
            dummy=dummy->next;
            cnt++;
        }
        return sh;
    }
};