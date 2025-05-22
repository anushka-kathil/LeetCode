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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list1;
        int i=0,j=0;
        // while(temp != nullptr){
        //    if(i == )

        // }
        while(i != a-1){
            temp=temp->next;
            i++;
        }
        ListNode* temp2 = temp->next;
        temp->next = list2;
        
        while(i != b){
            temp2=temp2->next;
            i++;
        }

        if(temp2 == nullptr){
          return list1;
        }

        ListNode* tlist2=list2;
        ListNode* prev;
        while(tlist2 != nullptr){
            prev = tlist2;
            tlist2 = tlist2->next;
        }
        
        prev->next = temp2;
        return list1;
    }
};