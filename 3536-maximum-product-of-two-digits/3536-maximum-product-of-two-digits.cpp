class Solution {
public:
    int maxProduct(int n) {
        vector<int> v;
        int k = n;
        int digit=0;
        while(k){
            int d = k%10;
            digit++;
            v.push_back(d);
            k=k/10;
        }
        sort(v.begin(),v.end());
        return v[digit-1]*v[digit-2]; 
    }
};