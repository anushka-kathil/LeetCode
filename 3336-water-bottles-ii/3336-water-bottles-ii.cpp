class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        if(numBottles < numExchange) return numBottles;
        int d = numBottles;
        int emp = numBottles;
        while(emp >= numExchange){
            emp-=numExchange;
            numExchange++;
            d++;
            emp++;
        } 
        return d;
    }
};