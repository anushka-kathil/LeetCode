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
    int dfs(TreeNode* root, int& sum, int targetSum){
        if(root == NULL) return false;
        sum+=root->val;
        if(root->left == NULL && root->right == NULL && targetSum == sum) return true;
        // cout<<sum<<endl;
        if(dfs(root->left,sum,targetSum) || dfs(root->right,sum,targetSum)){
        return true;
        }
        sum-=root->val;
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        int sum=0;
        return  dfs(root,sum,targetSum) ;   
    }
};