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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp=head;
        vector<int> v;
        while(temp!=nullptr){
            v.push_back(temp->val);
            temp=temp->next;
        }
        vector<int> ans;
        for(int i=0;i<v.size()-1;i++){
            int c=0;
            for(int j=i+1;j<v.size();j++){
               if(v[i] < v[j]){
                c++;
               ans.push_back(v[j]);
               break;}
            }
            if(c==0){
                ans.push_back(0);
            }
        //    ans.push_back(*max_element(v.begin()+i,v.end()));
        //    if(v[i] == ans[i]){
        //     ans.pop_back();
        //     ans.push_back(0);
        //    }
        }
        ans.push_back(0);
        return ans;
    }
};