/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *temp1=headA;
        int cnt1=0;
        while(temp1!=NULL){
            cnt1++;
            temp1=temp1->next;

        }
        ListNode *temp2=headB;
        int cnt2=0;
        while(temp2!=NULL){
            cnt2++;
            temp2=temp2->next;

        }
        temp1=headA;
        temp2=headB;
        if (cnt1>cnt2){
            for(int i=0;i<cnt1-cnt2;i++){
            temp1=temp1->next;
            }

        }
        else {
            for(int i=0;i<cnt2-cnt1;i++){
            temp2=temp2->next;
            }
        }
       
        
        while(temp1!=NULL && temp2!=NULL){
            if(temp1==temp2)return temp2;
            temp1=temp1->next;
            temp2=temp2->next;

        }
        return NULL;
        
    }
};