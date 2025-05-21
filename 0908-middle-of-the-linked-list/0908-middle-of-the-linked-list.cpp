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
    ListNode* middleNode(ListNode* head) {
        if(!head || !head->next)
        return head;
        int n=0;
        ListNode* temp = head;
        while(temp != nullptr){
            temp=temp->next;
            n++;
        }
        int k = n/2 + 1;
        int i=0;
        while(i!=(k-1)){
            head=head->next;
            i++;
        }
        return head;
    }
};