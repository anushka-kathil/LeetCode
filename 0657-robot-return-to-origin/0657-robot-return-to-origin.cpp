class Solution {
public:
    bool judgeCircle(string moves) {
        int r=0,l=0,u=0,d=0;
        for(int i=0; i<moves.size(); i++){
            if(moves[i]=='R' && l==0) r++;
            else if(moves[i]=='R' && l!=0) l--; 
            // else if(moves[i]=='R' && l!=0) r--;
            else if(moves[i]=='L' && r==0) l++;
            else if(moves[i]=='L' && r!=0) r--;
            else if(moves[i]=='U' && d==0) u++;
            else if(moves[i]=='U' && d!=0) d--;
            else if(moves[i]=='D' && u==0) d++;
            else if(moves[i]=='D' && u!=0) u--;
           
        }
        if(r==0 && l==0 && u==0 && d==0) return true;
        return false;
            
        }
};