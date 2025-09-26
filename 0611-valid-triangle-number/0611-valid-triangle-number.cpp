class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j,k;
        int c=0;
        while(i<(n-2)){
            j=i+1;
            while(j<(n-1)){
                k=n-1;
                //  cout<<i<<"**"<<j<<"**"<<k<<endl;
                while(k>j){
                    if(nums[i]+nums[j]>nums[k]){
                        // cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<endl;
                        c+=(k-j);
                        break;
                    }
                    k--;
                }
                j++;
            }
            i++;
        }
        return c;
    }
};