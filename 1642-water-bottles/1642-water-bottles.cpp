class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        if(numBottles < numExchange) return numBottles;
        int b = numBottles;
        int ans=0;
            while(b >= numExchange){
                ans+=numExchange;
                b-=numExchange;
                if(b>=numExchange || (b+1) == numExchange){
                    b++;
                }
                else{
                    ans+=b+1;
                    break;
                }
            }
          
        return ans;
    }
};