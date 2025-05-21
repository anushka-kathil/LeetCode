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
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        vector<int> v;
        while(temp!=nullptr){
        v.push_back(temp->val);
        temp = temp->next;
        }
        int sum=0;
        for(int i=0;i<v.size();i++){
            sum=max(sum, v[i] + v[v.size()-i-1]);
        }
        return sum;

    }
};