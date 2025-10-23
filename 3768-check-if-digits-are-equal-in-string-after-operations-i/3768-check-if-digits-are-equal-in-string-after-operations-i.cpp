class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        string ns=s;
        vector<char> v;
        while(ns.size()>2){
            v.clear();
            for(int i=0; i<ns.size()-1;i++){
                int a = ns[i] - '0';
                int b = ns[i + 1] - '0';
                int sum = (a + b) % 10;
                v.push_back(sum);
            }
            ns.clear();
            for(auto i:v){
                ns+=to_string(i);
            }
        }
        if(ns[0] == ns[1]) return true;
        else return false;

        
    }
};