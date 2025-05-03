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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head->next == nullptr)
        return head;

        ListNode* temp = head;
        int n=0;
        vector<vector<int>> ans;
        vector<int> v;
        while(temp!=nullptr){
            n++;
            if(n<=k){
                v.push_back(temp->val);
                temp=temp->next;
            }
            else{
                n=0;
                reverse(v.begin(),v.end());
                ans.push_back(v);
                v.clear();
            }    
        }  
    
        ListNode* temp1 = new ListNode(-1);
        ListNode* newHead = temp1;
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[0].size();j++){
                ListNode* newNode = new ListNode(ans[i][j]);
                temp1->next = newNode;
                temp1=temp1->next;                
            }
        }
        int v_n=0;
        if(v.size() == k){
            reverse(v.begin(),v.end());
        }
        while(v_n < v.size()){
            ListNode* newNode = new ListNode(v[v_n]);
            temp1->next = newNode;
            temp1=temp1->next;  
            v_n++;  
        }
        return newHead->next;
    }
};