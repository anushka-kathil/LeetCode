class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int row=matrix.size();
        int column = matrix[0].size();
        vector<int> r;
        vector<int> c;

        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(matrix[i][j] == 0){
                    r.push_back(i);
                    c.push_back(j);
                }
            }   
        }

        map<int,bool> m;
        int ri=0;

        while(ri<r.size()){
            // cout<<"**";
            if(m[r[ri]]==false){
            for(int i=0;i<column;i++){
                matrix[r[ri]][i]=0;
            }
            }
            m[r[ri]]=true;
            ri++;
        }
        m.clear();
        int ci=0;
        while(ci<c.size()){
            if(m[c[ci]]==false){
            for(int i=0;i<row;i++){
                matrix[i][c[ci]]=0;
               }
            }
            m[c[ci]]=true;
            ci++;
        }   
    }
};