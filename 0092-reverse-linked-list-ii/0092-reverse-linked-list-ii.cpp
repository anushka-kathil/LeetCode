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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next){
            return head;
        }
       vector<int> v;
       ListNode* temp=head;
       int pointer=1;
       while(temp!=nullptr){
        if(pointer>=left && pointer<=right){
            v.push_back(temp->val);
        }
        pointer++;
        temp=temp->next;
       } 

       reverse(v.begin(),v.end());
       temp=head;
       pointer=1;
       int i=0;
       while(temp!=nullptr){
        if(pointer>=left && pointer<=right){
           temp->val=v[i];
           i++;
        }
        pointer++;
        temp=temp->next;
       }
       return head;
    }
};