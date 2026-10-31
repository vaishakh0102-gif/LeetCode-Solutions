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
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)return head;
        ListNode *temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        int run=cnt/k;
        int i=0;
        temp=head;
        ListNode *prevTail=NULL;
        ListNode *newHead=nullptr;
       
        
        while(i<run){
            ListNode *back=nullptr;
            ListNode *groupTail=temp;
            for(int j=0;j<k;j++){
                ListNode *front=temp->next;                
                temp->next=back;
                
                back=temp;
                temp=front;
               
            }
            if(i==0)newHead=back;
            if(prevTail!=NULL)prevTail->next=back;
            prevTail=groupTail;

            i++; 
                
        }
        if(prevTail!=NULL){
            prevTail->next=temp;

        }
        
        return newHead!=NULL?newHead:head;
        


        
    }
};