class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        long long prod=1;
        // long long cnt=0;
        vector<int> pairs;
        sort(potions.begin(),potions.end());
        for(int i=0; i<n; i++){
            long long start=0,end=m-1,idx=m,cnt=0;
            while(start<=end){
                long long mid = start + (end-start)/2;
                prod = 1LL*spells[i]*potions[mid];
                if(prod>=success){
                    idx=mid;
                    end=mid-1;
                }
                else{
                    start = mid+1;
                }    
            }
            if(idx==m) cnt=0;
            else cnt = m-idx;
            pairs.push_back(cnt);
        }





        // for(int i=0; i<n; i++){
        //     // cnt=0;
        //     for(int j=0; j<m; j++){
        //         long long prod1=1LL*spells[i]*potions[m-1];
        //         prod=1LL*spells[i]*potions[j];
        //        if(prod1 < success){cnt=0;
        //        break;}
        //        if(prod >= success) {
        //         // cout<<m<<" "<<i<<"="<<prod<<endl;
        //         cnt=m-j;
        //         break;
        //        }
        //     }
        //     pairs.push_back(cnt);
        // }
        return pairs;
        
    }
};