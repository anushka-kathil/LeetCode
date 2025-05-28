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
// METHOD 2
   void level(TreeNode* node, vector<int>& v, int l){
       if(node == NULL) return;
       if(v.size() == l)
         v.push_back(node->val);
        
        level(node->right,v,l+1);
        level(node->left,v,l+1);
        
   }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        level(root,v,0);
        return v;

        // METHOD 1
        // if(!root) return v;
        
        // queue<TreeNode*> q;
        // q.push(root);
        
        // while(q.size()){
        //     int size = q.size();
        //     vector<int> level;
        //     for(int i=0;i<size;i++){
        //      TreeNode* node = q.front();
        //      q.pop();

        //      level.push_back(node->val);
        //         if(node->left) q.push(node->left);
        //         if(node->right) q.push(node->right);
        //     }
        //     v.push_back(level[level.size()-1]);
        // }
        // return v;
        
    }
};