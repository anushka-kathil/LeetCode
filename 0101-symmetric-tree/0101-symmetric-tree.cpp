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
    bool isSymmetric(TreeNode* root) {
        vector<int> vL,vR;
        if(root!=NULL){
            vL.push_back(root->val);
            vR.push_back(root->val);
        }
        pL(root->left, vL);
        pR(root->right, vR);
        // cout<<vL.size()<<" "<<vR.size()<<endl;
        // for(int i=0; i<vL.size(); i++) cout<<vL[i]<<" ";
        // cout<<endl;
        //  for(int i=0; i<vR.size(); i++) cout<<vR[i]<<" ";
        return vL==vR;
        
    }
    vector<int> pL(TreeNode* root,vector<int>& vL){
        if(root==NULL) {vL.push_back(-1); return vL;}
        
        vL.push_back(root->val);
        pL(root->left,vL);
        pL(root->right,vL);
        return vL;
    }

    vector<int> pR(TreeNode* root,vector<int>& vR){
        if(root==NULL){ vR.push_back(-1); return vR;}
        vR.push_back(root->val);
        pR(root->right,vR);
        pR(root->left,vR);
        
        return vR;
    }
};