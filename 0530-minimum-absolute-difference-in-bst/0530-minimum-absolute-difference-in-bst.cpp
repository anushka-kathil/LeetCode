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
    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        TreeNode* cur = root;
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<q.size(); i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                v.push_back(node->val);
            }
        }
        sort(v.begin(),v.end());
        int mini=INT_MAX;
        for(int i=0; i<v.size()-1;i++){ 
            if(abs(v[i]-v[i+1])<mini) mini=abs(v[i]-v[i+1]);
        }
        return mini;
        
    }
};