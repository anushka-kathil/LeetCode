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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)
        return l2;
        else if(!l2)
        return l1;
        ListNode* temp1 = l1;
        ListNode* temp2= l2;
        vector<int> v1;
        vector<int> v2;
        while(temp1 != nullptr){
            v1.push_back(temp1->val);
            temp1=temp1->next;
        }
        reverse(v1.begin(),v1.end());
        while(temp2 != nullptr){
            v2.push_back(temp2->val);
            temp2=temp2->next;
        }
        reverse(v2.begin(),v2.end());
        vector<int> v3;
        while(v1.size() != v2.size()){
            if(v1.size() < v2.size())
            v1.push_back(0);
            else
            v2.push_back(0);
        }
        int c=0;
        int l=0;
        
        for(int i=0;i<v1.size();i++){
           int sum = v1[i]+v2[i]+c;
           v3.push_back(sum % 10);
           c=(sum>9) ? 1:0;
           l=sum/10;
        }
        if(l!=0)
        v3.push_back(l);

        reverse(v3.begin(),v3.end());
        ListNode* newHead= new ListNode(v3[0]);
        ListNode* temp3=newHead;
        // newHead->next = nullptr;
        for(int i=1;i<v3.size();i++){
            ListNode* newnode = new ListNode(v3[i]);
            temp3->next=newnode;
            temp3=temp3->next;
        }
        temp3->next=nullptr;
        return newHead;
    }
};