class Solution {
public:
    int check(int x){
    while(x>0){
        if(x%10 == 0) return false;
        x=x/10;
    }
    return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        // vector<int> v;
        for(int i=1; i<n; i++)
        {
            int k = n-i;
            if(check(i) && check(k)){
                return {i,k};
            }

        }
        return {};
        
    }
};