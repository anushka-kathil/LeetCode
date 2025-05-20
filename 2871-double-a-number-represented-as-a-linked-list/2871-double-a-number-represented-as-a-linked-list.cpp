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
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp = head;
        vector<int> v;
        while(temp != nullptr){
            v.push_back(temp -> val);
            temp=temp->next;
        }
        
        reverse(v.begin(),v.end());
        int carry=0;
        int l=0;
        for(int i=0;i<v.size();i++){
          int sum = v[i] + v[i] + carry;
        //   if(i != v.size() - 1)
          v[i] = (sum) % 10;

        //   else
        //   v[i]=sum;

          if(sum > 9)
          carry = 1;
          else
          carry=0;
         
         l=sum/10;
          
        }

        reverse(v.begin(),v.end());
        ListNode* newhead;
        if(l!=0){
             newhead = new ListNode(1);
            newhead->next = head;
        }

        temp = head;
        
        int i=0;
        while(temp != nullptr){
            temp->val = v[i];
            temp = temp->next;
            i++;
        }
        if(l == 0){
        // cout<<l<<endl;
        return head;}

        else{
            //   cout<<l<<endl;
        // cout<<newhead->val;
        return newhead;}
 
    }
};