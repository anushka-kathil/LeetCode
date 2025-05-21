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
    int gcd(int i1, int i2){
        int num=1;
        for(int i=2;i<=min(i1,i2);i++){
            if(i1 % i == 0 && i2%i == 0){
                num=i;
            }
        }
        return num;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next)
        return head;

        ListNode* temp = head;
        while(temp->next!=nullptr){
            int add = gcd(temp->val, temp->next->val);
            ListNode* newNode = new ListNode(add);
            ListNode* temp1 = temp->next;
            temp->next = newNode;
            temp=temp->next;
            temp->next=temp1;
            temp=temp->next;
        }
        return head;
    }
};