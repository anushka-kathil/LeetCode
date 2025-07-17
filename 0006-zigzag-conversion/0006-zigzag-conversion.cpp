class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if(numRows==1 || n<=numRows) return s;
        vector<vector<int>> v(numRows);
        int index=0,d=1;
        for(auto& c:s){
            v[index].push_back(c);
            if(index==0) d=1;
            else if(index == numRows-1) d=-1;
            index+=d;   
        }
        string ans="";
        for(auto i:v){
            for(auto c:i){
            ans+=c;
            }
        }
        return ans;
        // int row=0,col=0;
        // int n=s.length();
        // int pos = -1;
        // for(int i=0; i<n;i++){
        //     for(int j=0; j<numRows; j++){
        //         pos++;
        //        v[j][i]=s[pos];
        //     }

        // }
        // int i=0;
        // while (i<n){
        //     row=0;
        //     while (row < numRows && i<n){
        //         v[row][col] = s[i];
        //         row++;
        //         i++;
        //     }
        //     col++;
        //     row-=2;
        //     i++;
        //     while(row>0  && i<n){
        //         v[row][col]=s[i];
        //         i++;
        //         row--;
        //         col++;
        //     }
        // }
        // string ans="";
        // for(int i=0;i<v.size();i++){
        //     for(int j=0;j<v[0].size();j++){
        //         ans+=v[i][j];
        //     }
        // }
        // return ans;
    }
};