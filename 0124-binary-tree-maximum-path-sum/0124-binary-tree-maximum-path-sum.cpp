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
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        sm(root,sum);
        return sum;
    }

private:
    int sm(TreeNode* root, int& sum){
        if(root == NULL) return 0;
        int lh = max(0,sm(root->left,sum));
        int rh = max(0,sm(root->right, sum));
        // if(lh<0 || rh<0) return 0; // to avoid negative values at longest path
        sum = max(sum,root->val+lh+rh); // to calculate maximum sum
        return root->val+max(lh,rh); // to choose longest path which can give use max sum
    }
};