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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp=l1;
        ListNode* curr=l2;
        int carry=0;
        
        ListNode* sumHead=new ListNode(0);
        ListNode* sumcurr=sumHead;
        
        while(temp!=NULL || curr!=NULL|| carry!=0){
            int sum=carry;
            if(temp!=NULL){
                sum+=temp->val;
                temp=temp->next;

            }
            if(curr!=NULL){
                sum+=curr->val;
                curr=curr->next;

            }
            
            if(sum>9){
                carry=1;
                
                sumcurr->next=new ListNode(sum%10);

            }
            else{
                carry=0;
                sumcurr->next=new ListNode(sum);

            }
            
            sumcurr=sumcurr->next;
            
        

        }
        
        return sumHead->next;

        



        
    }
};