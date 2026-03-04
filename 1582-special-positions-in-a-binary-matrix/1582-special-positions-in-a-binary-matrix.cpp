class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
      
        int c=0,sum=0,col=-1;
        bool flag=false;
        for(int i=0; i<n; i++){
            sum=0;
            flag=false;
            col=-1;
            for(int j=0; j<m; j++){
                sum+=mat[i][j];
                if(mat[i][j] == 1){ 
                col = j;
                }
                // cout<<"SUM="<<sum<<endl;
                if(sum>1) {flag=true; break;}
            }
            if(col != -1){
            for(int k=0; k<n; k++){
                if(flag==true) break;
                sum+=mat[k][col];
            }
            }
            if(sum==2 && flag==false) c++;
        }
        return c;
    }
};