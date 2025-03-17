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
    ListNode* swapPairs(ListNode* head) {
        if( head == NULL)
        return NULL;
        if(head->next == nullptr )
        return head;

        ListNode* curr=head;
        ListNode* prev=new ListNode(0);
        
        ListNode* ans=head->next;
        // ListNode* store=head;

        while(curr && curr->next != NULL ){
            ListNode* third=curr->next->next;
            ListNode* second=curr->next;

            second->next=curr;
            curr->next=third;
            prev->next=second;

            prev=curr;
            curr=curr->next;
        }
        return ans;


        
    }
};