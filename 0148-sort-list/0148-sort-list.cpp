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
private:
    ListNode *merge(ListNode *leftsorted,ListNode *rightsorted){
        ListNode *dummy=new ListNode (-1);
        ListNode *temp=dummy;

        ListNode *left=leftsorted;
        ListNode *right=rightsorted;
        while(left!=NULL && right!=NULL){
            if(left->val<=right->val){
                temp->next=left;
                temp=left;
                left=left->next;
            }

            else{
                temp->next=right;
                temp=right;
                right=right->next;
            }

        }
        if(left!=NULL){
            temp->next=left;

        }
        else {
            temp->next=right;
        }
        ListNode *sortedhead=dummy->next;
        delete dummy;
        return sortedhead;       
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)return  head;
        ListNode *low=head;
        ListNode *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        ListNode *high=temp;
        int cnt=0;
        temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        temp=head;
        int i=0;
        ListNode *mid=head;
        while(i<(cnt-1)/2){
            mid=mid->next;
            i++;
        }
        
        ListNode *righthalf=mid->next;
        mid->next=NULL;
        ListNode *leftsorted= sortList(head);
        ListNode *rightsorted= sortList(righthalf);
        return merge(leftsorted,rightsorted);
        
    

        
        
    }
};