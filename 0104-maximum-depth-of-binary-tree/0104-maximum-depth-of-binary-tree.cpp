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
// using recursion
    // int maxDepth(TreeNode* root) {
    //     if(root == nullptr) return 0;
    //     int l = maxDepth(root->left);
    //     int r = maxDepth(root->right);
    //     return 1+max(l,r);     
    // }

    // using level order or bfs
    int maxDepth(TreeNode* root) {
       if(root == nullptr) return 0;
       int ans =0;
    //    int l=0,r=0;
       queue<TreeNode*> q;
       q.push(root);
       while(!q.empty()){
        int size= q.size();
        
        for(int i=0;i<size;i++){
        TreeNode* node=q.front();
        q.pop();

        if(node->left != nullptr){ q.push(node->left);}
        if(node->right != nullptr){ q.push(node->right);}
        }
        ans++;
       }
       return ans;
    }
};