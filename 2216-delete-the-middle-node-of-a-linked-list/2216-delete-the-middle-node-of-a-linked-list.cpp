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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp = head;
        int n=0;
        while(temp!=nullptr){
            n++;
            temp=temp->next;
        }

        if(n==1)
        return nullptr;

        temp = head;
        ListNode* prev = nullptr;
        int mid=n/2 ;
        while(mid--){
            prev=temp;
            temp=temp->next;
        }
       
        prev->next=temp->next;
        temp->next=nullptr;
        return head;
        
    }
};