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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        return;
        
        int len = 0;
        vector<ListNode*> v;
        ListNode* temp=head;
        while(temp != nullptr){
            len++;
            temp=temp->next;
        }

        int k=1;
        temp=head;
        while(temp!=nullptr){
          v.push_back(temp);
          temp=temp->next;
        }

        int n = v.size();
        int i = 0;
        ListNode* temp1 = head;
        temp1->next = v[n-i-1];
        temp1 = temp1->next;
        i++;
        while(i != n/2){
         temp1->next = v[i];
         temp1 = temp1->next;
         temp1->next = v[n-i-1];
         temp1 = temp1->next;
         i++;
        }
        if(n%2 == 0)
        temp1->next = nullptr;

        else{
        temp1->next = v[i];
        temp1 = temp1->next;
        temp1->next = nullptr;
        }
     
     return;

    }
};