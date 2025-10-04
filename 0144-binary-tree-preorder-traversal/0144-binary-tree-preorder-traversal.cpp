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
// private:
//     void traverse(TreeNode* node, vector<int>& v){
//         if(node == nullptr)
//         return;
        
//         v.push_back(node->val);
//         traverse(node->left,v);
//         traverse(node->right,v);
//     }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        // vector<int> v;
        // traverse(root,v);
        // return v;
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(st.size()){
            TreeNode* node = st.top();
            st.pop();
            if(node->right!=NULL)
            st.push(node->right);
            if(node->left!=NULL)
            st.push(node->left);
            ans.push_back(node->val);    
        }
        return ans;
    }
};