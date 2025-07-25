class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string>> v{
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90,"XC"}, {50, "L"}, {40,"XL"}, {10, "X"}, {9,"IX"}, {5, "V"}, {4,"IV"}, {1,"I"}
        };

        string res;
        for(auto i:v){
            int val = i.first;
            string symbol = i.second;
            if (num==0) break;

            while(num >= val){
                res+=symbol;
                num-=val;
            }
        }
        return res;  
    }
};