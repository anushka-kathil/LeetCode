class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        if((long long)numerator % denominator == 0) return to_string((long long) numerator/denominator);
        string res="";
        if(numerator<0 ^ denominator<0) res+="-";
        long long num = llabs((long long) numerator);
        long long den = llabs((long long) denominator);
        res += to_string(num/den);
        res.push_back('.');
        long long rem = num%den;
        unordered_map<long long,long long> m;
        while(rem!=0){
            if(m.find(rem)!= m.end()){
                res.insert(m[rem],"(");
                res.push_back(')');
                break;
            }
            m[rem]=res.size();
            rem*=10;
            res.push_back((rem/den) + '0');
            rem %= den;
        }
        return res;        
    }
};