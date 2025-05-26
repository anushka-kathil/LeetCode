/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
//    void reverseQueue(queue<TreeNode*>& q)
// {
//     stack<TreeNode*> s;
//     while (!q.empty()) {
//         s.push(q.front());
//         q.pop();
//     }
//     while (!s.empty()) {
//         q.push(s.top());
//         s.pop();
//     }
// }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        
        queue<TreeNode*> q;
        int k=1;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            // if(k%2 != 0){
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);

                level.push_back(node->val);

            }
            if(k%2 !=0)
            ans.push_back(level);
            else{
                reverse(level.begin(),level.end());
                ans.push_back(level);
            }
            // }

            // else{
               
            //    for(int i=0;i<size;i++){
            //     TreeNode* node = q.front();
            //     q.pop();
            //     if(!node->left) q.push(node->left);
            //     if(!node->right) q.push(node->right);
            //     level.push_back(node->val);
            // }
            // ans.push_back(level);
            // }
            k++;
        }
        return ans;


    }
};