class Solution {
private:
    static bool cmp(string a, string b){
        // int x = a<10?a:a/10;
        // int y = b<10?b:b/10;
        return (b+a) < (a+b);
    }
public:
    
    string largestNumber(vector<int>& nums) {
        vector<string> snums;
        for(int i=0; i<nums.size();i++){
         snums.push_back(to_string(nums[i]));
        }
        sort(snums.begin(),snums.end(),cmp);
        if(snums[0] == "0") return "0";
        string ans="";
        for(int i=0; i<snums.size();i++){
        ans+=snums[i];
        }
        return ans;
    }
};