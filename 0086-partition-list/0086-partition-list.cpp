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
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr)
        return nullptr;
        ListNode* temp=head;
        vector<int> small;
        vector<int> large;
        while(temp!=nullptr){
            if(temp->val < x)
            {
                small.push_back(temp->val);
            }
            else{
                large.push_back(temp->val);
            }
            temp=temp->next;
        }
     
     for(int i=0;i<large.size();i++){
        small.push_back(large[i]);
     }
    
    ListNode* newHead = new ListNode(small[0]);
    ListNode* temp1 = newHead;
     for(int i=1;i<small.size();i++){
     ListNode* newNode = new ListNode(small[i]);
     temp1->next=newNode;
     temp1=temp1->next;
     }

     return newHead;

        
    }
};