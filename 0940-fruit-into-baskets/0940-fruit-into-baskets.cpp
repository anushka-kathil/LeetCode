class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if(n==0)
        return 0; 
        if(n==1)
        return 1;
        int l=0,r=0;
        map<int,int> m;
        int maxlen=0;
        while(r<n){
           m[fruits[r]]++;
           if(m.size()>2){
            m[fruits[l]]--;
            if( m[fruits[l]]==0)
            m.erase(fruits[l]); 
            l++;
           }
           if(m.size()<=2){
            maxlen=max(maxlen, r-l+1);
           }
           r++;
        }
        return maxlen;     
    }
};