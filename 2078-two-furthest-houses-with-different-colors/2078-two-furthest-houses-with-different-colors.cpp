class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int d=0;
        for(int i=0; i<n; i++){
            for(int j=n-1;j>i; j--){
                if(colors[i] != colors[j]) {
                    d=max(d,abs(i-j));
                }
            }
        }
        return d; 
    }
};