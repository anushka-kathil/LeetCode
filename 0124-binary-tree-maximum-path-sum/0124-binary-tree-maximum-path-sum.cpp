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
    int findMax(TreeNode* root, int& maxi){
        if(root == nullptr) return 0;
        int lh = max(0, findMax(root->left, maxi));
        int rh =  max(0, findMax(root->right, maxi));
        maxi=max(maxi, lh+rh+root->val);
        return root->val + max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        if(!root->left && !root->right) return root->val;
        int maxi=INT_MIN;
        findMax(root,maxi);
        return maxi;
        
    }
};