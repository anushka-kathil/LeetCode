class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        for(int i=left; i<=right; i++){
            if(i!=0 && i<10){
                v.push_back(i);
            }
            else{
                if(i==0) continue;
                int k=i;
                bool flag=true;
                while(k){
                    int d=k%10;
                    k=k/10;
                    if(d==0 || i%d != 0) {
                        flag=false; 
                        break;
                    }
                   
                }
                if(flag==true) v.push_back(i);
            }
        }
        return v;
    }
};