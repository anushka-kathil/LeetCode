class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        int m=INT_MIN;
        for(int i=0; i<n-2; i++){
            if(num[i] == num[i+1] && num[i+1] == num[i+2]){
                m = max(m, stoi(num.substr(i,3)));
            }
        }
        if(m==INT_MIN) return "";
        else if(m==0) return "000";
        return to_string(m);
        
    }
};