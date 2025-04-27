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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        // if(lists.empty())
        // return nullptr;

        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];
            while (temp != nullptr) {
                v.push_back(temp->val);
                temp = temp->next;
            }
        }

        sort(v.begin(), v.end());

        if(v.empty()){
            return nullptr;
        }
        
        ListNode* newHead= new ListNode(v[0]);
        ListNode* temp=newHead;

        for(int i=1;i<v.size();i++){
          ListNode* newNode= new ListNode(v[i]);
          temp->next=newNode;
          temp=temp->next;
        }
        return newHead;
        
        
    }
};