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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int lh=leftHeight(root);
        int rh=rightHeight(root);
        if(lh==rh) return (1<<lh)-1;
        
        return 1+countNodes(root->left)+countNodes(root->right);
    }

   int leftHeight(TreeNode* node){
    // if(node==NULL) return ;
    int lh=0;
     while(node){
        lh++;
        node=node->left;
        }
    return lh;
    }

    int rightHeight(TreeNode* node){
    int rh=0;
     while(node){
        rh++;
        node=node->right;
        }
    return rh;
    }

};