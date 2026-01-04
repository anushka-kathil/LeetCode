class Solution {
public:
    int summ(int n, vector<int>& v){
        int ans=0,c=0;
        for(int i=1; i<=n; i++){
            if(n%i == 0){
                c++;
                ans+=i;
                if(c>4) {
                v[n]=0;
                return 0;}
            }
        }
        if(c<4){ v[n]=0; return 0;}
        v[n]=ans;
        return ans;
    }

    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(100001,-1);
        int ans=0;
        for(int i=0; i<n; i++){
            if(v[nums[i]]!=-1){
                ans+=v[nums[i]]; continue;
            }
            ans+=summ(nums[i],v);
        }
        return ans;
        
    }
};