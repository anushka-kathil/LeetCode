class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int n=;
        int x=0;
        for(int i=0;i<nums.size();i++){
          x= x^nums[i];
        }
        
        unordered_map<int,int> m;
        m[2] = 6;
        m[1] = 78;
        m[9] = 2; 
        m[3] = 0;  
        for(auto it:m){
        cout<<it.first<<" "<<it.second<<endl;}
        return x;
    }
};