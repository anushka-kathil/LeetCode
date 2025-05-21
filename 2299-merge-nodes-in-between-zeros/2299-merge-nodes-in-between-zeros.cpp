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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head;
        vector<int> v;
        int sum=0;
        while(temp!=nullptr){
            if(temp->val == 0 && sum>0){
                v.push_back(sum);
                sum=0;
            }
            else if(temp->val == 0 && sum==0) continue;
            else sum+=temp->val;

            temp=temp->next;
        }

        ListNode* newHead=new ListNode(v[0]);
        temp=newHead;
        for(int i=1;i<v.size();i++){
            ListNode* newNode=new ListNode(v[i]);
            temp->next = newNode;
            temp=temp->next;
        }
        temp->next=nullptr;
        return newHead;

        
    }
};