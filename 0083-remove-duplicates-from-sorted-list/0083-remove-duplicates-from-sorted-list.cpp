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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)return head;
        ListNode *temp=head;
        while(temp!=NULL && temp->next!=NULL){
            ListNode * front=temp->next;
            if(temp->val ==front->val){
                    temp->next=front->next;
                       
            }
            else {
    
                temp=temp->next;
            }
            
            
        }
        return head;
        
    }
};