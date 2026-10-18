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
    ListNode* reverse(ListNode* head){
       
        if(head==nullptr || head->next==nullptr)return head;
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)return head;
        ListNode *temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        if(k==0)return head;
        k=k%cnt;
        

        temp=head;
        for(int i=0;i<cnt-k-1;i++){
            temp=temp->next;
        }
        ListNode *secondhalf=temp->next;
        temp->next=nullptr;

        ListNode *rev1=reverse(head);
        ListNode *rev2=reverse(secondhalf);

        head->next=rev2;
        ListNode *rev3=reverse(rev1);
        return rev3;
        
        
    }
};