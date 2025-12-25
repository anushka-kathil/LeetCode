class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
        int sum = accumulate(apple.begin(),apple.end(),0);
        sort(capacity.begin(),capacity.end(),greater<int>());
        int c=0,ans=0;
        for(int i=0; i<m; i++){
            c+=capacity[i];
            if(c<sum) ans++;
            else if(c >= sum){
                ans++;
                break;
            }
            
        }
        return ans;
    }
};