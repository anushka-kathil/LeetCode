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
    // void check(TreeNode* r, TreeNode* l,vector<int>& v){
    //    if(!r && !l) return;
    //    if(r!= NULL){
    //     v.push_back(r->val);
    //     if(r->right != NULL && l->)
    //     check()

    //     else if(r->)
    //    }

    // }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(!root) return v;
        // check(root->right,root->left,v);
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()){
            int size = q.size();
            vector<int> level;
            for(int i=0;i<size;i++){
             TreeNode* node = q.front();
             q.pop();

             level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            v.push_back(level[level.size()-1]);
        }
        return v;
        
    }
};