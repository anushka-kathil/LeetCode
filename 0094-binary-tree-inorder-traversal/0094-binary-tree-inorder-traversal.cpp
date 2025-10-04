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
//    void traverse(TreeNode* node,vector<int>& v){
//         if(!node)
//         return;

//         traverse(node->left,v);
//         v.push_back(node->val);
//         traverse(node->right,v);
//         // v.push_back(node->val);

//    }
    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int> v;
        // traverse(root,v);
        // return v;
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> st;
        // st.push(root);
        TreeNode* node = root;
        while(true){
            if(node != NULL){
               st.push(node);
               node=node->left;
            }
            else{
                if(st.empty()==true) break;
                  node = st.top();
                  st.pop();
                 ans.push_back(node->val);
                 node=node->right;
            }
        }
        return ans;
    }


};