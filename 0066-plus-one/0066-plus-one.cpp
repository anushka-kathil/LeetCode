class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans(n,0);
        bool flag = false;
        int sum = count(digits.begin(),digits.end(),9);
        if(sum == n){
            ans.insert(ans.begin(), 1);  
            return ans;
        }
        else if(digits[n-1] < 9){
            ans = digits;
            ans[n-1] = digits[n-1]+1;
            return ans;
        }
        else{
            ans=digits;
            for(int i=n-1; i>=0; i--){
                if(ans[i] == 9){
                    ans[i] = 0;
                }
                else{
                ans[i]++;
                 break;
                }
            }

        }
        return ans;   
    }
};