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
    static bool cmp(ListNode* a, ListNode* b){
        return a->val<b->val;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        vector<ListNode*> v;
        ListNode* temp = head;
        while(temp!=nullptr){
            v.push_back(temp);
            temp=temp->next;
        }
        sort(v.begin(),v.end(),cmp);
        ListNode* newHead = new ListNode(v[0]->val);
        ListNode* temp1 = newHead;
        for(int i=1;i<v.size();i++){
            ListNode* newNode= new ListNode(v[i]->val);
            temp1->next=newNode;
            temp1=temp1->next;
        }

    //  ListNode* newHead = v[0];
    //  ListNode* temp1 = newHead;
    //  for(int i=1;i<v.size();i++){
    //         temp1->next=v[i];
    //         temp1=temp1->next;
    //     }
        temp1->next = nullptr;


     return newHead;
    }
};