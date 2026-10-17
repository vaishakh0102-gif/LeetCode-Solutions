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
    ListNode* reverse(ListNode *head){
         ListNode *back=nullptr;
        ListNode *temp=head;
       
        while(temp!=nullptr){
            ListNode *front=temp->next;

            
            temp->next=back;
            
            back=temp;
            temp=front;
            
        }
        return back;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)return true;
        
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            
        }
        ListNode *secondhalf=reverse(slow->next);
        fast=secondhalf;
        slow=head;
        
        while(fast!=NULL){
            if(slow->val!=fast->val)return false;
            slow=slow->next;
            fast=fast->next;

        }
        return true;
        
    }
};