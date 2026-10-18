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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)return NULL;
        ListNode *temp=head;
        ListNode *back=nullptr;
        while(temp!=NULL){
            if(temp->val==val){
                if(back==nullptr){
                    head=temp->next;
                    delete temp;
                    temp=head;
                }
                else{
                    ListNode *front=temp->next;
                    back->next=front;
                    delete temp;
                    temp=front;
                   

                    
                }
                


            }
            else {
                back=temp;
                temp=temp->next;

            }
        }
        return head;
        
    }
};