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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int n;
        vector<int> v;
        while(temp != nullptr){
            v.push_back(temp->val);
            temp = temp->next;
        }
        n=v.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans += v[i] * pow(2,(n-i-1));
        }
        return ans;
    }
};