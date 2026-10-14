/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,bool> visited;
        map<TreeNode*,TreeNode*> m;
        m[root]=NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            
            int sz=q.size();
            for(int i=0; i<sz; i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=NULL){ 
                    m[node->left] = node;
                    q.push(node->left);}
                if(node->right!=NULL){ 
                    m[node->right] = node;
                    q.push(node->right);}
            }
        }
        int dist=0;
        queue<TreeNode*> tg;
        // queue<TreeNode*> res;
        tg.push(target);
        
        while(dist<k && !tg.empty()){
            // cout<<"U**"<<endl;
            int sz=tg.size();
            for(int i=0; i<sz; i++){
                //  cout<<"###"<<endl;
                TreeNode* node=tg.front();
                tg.pop();
                visited[node]=true;
                if(node->left!=NULL && dist<k && visited[node->left]==false){  tg.push(node->left);}
                if(node->right!=NULL && dist<k && visited[node->right]==false){ tg.push(node->right);}
                if(m[node]!=NULL && visited[m[node]] == false && dist<k){  tg.push(m[node]);}
            }
            dist++;
            // cout<<"D= "<<dist<<endl;
        }
        vector<int> res;
        while(!tg.empty()){
            int value = tg.front()->val;
            tg.pop();
            res.push_back(value);
        }
        return res;
    }
};