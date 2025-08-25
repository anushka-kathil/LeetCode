class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
         int n = mat.size();
         int m = mat[0].size();
         vector<int> v(n*m);
         int r=0, c=0;
         for(int i=0; i<n*m; i++){
            v[i] = mat[r][c];
            if((r+c)%2 == 0){
                if(c == m-1) { r++; }
                else if(r==0) c++;
                else { r--; c++; }
            }
            else{
                
                 if(r==n-1){ c++; }
                 else if(c==0) r++;
                else {r++; c--;}
            }
         }
         return v;

        
    }
};