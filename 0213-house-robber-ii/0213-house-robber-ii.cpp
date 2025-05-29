class Solution {
public:

   int money(vector<int>& v){
    int prev2 = 0;
    int prev = v[0];
    for(int i = 1;i< v.size(); i++){
        int take = v[i];
        if(i>1) take+=prev2;

        int not_take = 0 + prev;
        int curr = max(take,not_take);
        prev2 = prev;
        prev= curr;
    }
    return prev;
   }


    int rob(vector<int>& nums) {
        int n= nums.size();
        // if(n==0 || n==2) return 0;
        if(n==1) return nums[0];
        // if(n<=3){
        //  sort(nums.begin(),nums.end(),greater<int>());
        //  return nums[0];
        // }
        // first and last can't come together
        vector<int> temp1(n-1);
        vector<int> temp2(n-1);
        for(int i=1; i<n; i++){
            temp1.push_back(nums[i]);
        }
        for(int i=0; i<n-1; i++){
            temp2.push_back(nums[i]);
        }
        cout<<money(temp1)<<" "<<money(temp2)<<endl;
        return max(money(temp1),money(temp2));
        
    }
};