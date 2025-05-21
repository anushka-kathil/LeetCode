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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int n=0;
        while(temp != nullptr){
            temp=temp->next;
            n++;
        }
        int i=1;
        temp=head;
        ListNode* temp1;
        ListNode* temp2;
        while(i!=k){
            temp=temp->next;
            i++;
        }
        temp1=temp;
        temp=head;
        int j=1;
        while(j!= n-k+1){
            temp=temp->next;
            j++;
        }
        temp2 = temp;

        swap(temp1->val,temp2->val);
        return head;




        
    }
};