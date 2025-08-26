class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        double diag,maxi=0.0;
        int area=0;
        for(int i=0; i<n; i++){
               diag = sqrt(dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1]);
               if(maxi < diag){
                maxi = diag;
                area = dimensions[i][0] * dimensions[i][1];
               }
               else if(maxi == diag){
                 area = max(area, dimensions[i][0] * dimensions[i][1]);
               }
        }
        return area;
    }
};