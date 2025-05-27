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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //  vector<vector<int>> ans;
        //  if(!root) return ans;
          map<int,map<int,multiset<int>>> nodes;
          queue<pair<TreeNode*,pair<int,int>>> todo;
          todo.push({root,{0,0}});
          while(todo.size()){
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y= p.second.second;
            nodes[x][y].insert(node->val);
            if(p.first->left){
                todo.push({p.first->left, {x-1,y+1}});
            }
            if(p.first -> right){
                todo.push({p.first->right, {x+1,y+1}});
            }
          }

          vector<vector<int>> res;
          for(auto p: nodes){
            vector<int> col;
            for(auto q:p.second){
               col.insert(col.end(),q.second.begin(),q.second.end());
            }
            res.push_back(col);
          } 
          return res;
    }
};