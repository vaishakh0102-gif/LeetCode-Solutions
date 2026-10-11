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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *temp1=list1;
        ListNode *temp2=list2;
        ListNode *dummy=new ListNode (0);
        ListNode *x=dummy;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val <= temp2->val){
                x->next=new ListNode(temp1->val);
                temp1=temp1->next;
                x=x->next;


            }
            else {
                x->next=new ListNode(temp2->val);
                temp2=temp2->next;
                x=x->next;
            }
        }
        while(temp1!=NULL){
            x->next=new ListNode(temp1->val);
            temp1=temp1->next;
            x=x->next;
        }
        while(temp2!=NULL){
            x->next=new ListNode(temp2->val);
            temp2=temp2->next;
            x=x->next;
        }

        return dummy->next;


        
    }
};