class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int dist = INT_MAX,c=0;
        for(int i=0; i<n; i++){

            if(words[i] == target){
                c++;
                dist=min(dist, abs(startIndex-i));
               
                if(startIndex<=i){
                    int sub = n-i+startIndex;
                    dist=min(dist,sub);
                }
                else{
                    int sub = abs(n-startIndex+i);
                    dist=min(dist,sub);
                }

            }
        }
        if(c==0) return -1;
        return dist;
        
    }
};