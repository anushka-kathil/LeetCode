class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        // TC = O(n), SC = O(n)
        
        // int total=0,leftMax,rightMax;
        // int prefix[n];
        // prefix[0]=height[0];
        // for(int i=1;i<n;i++){
        // prefix[i]=max(prefix[i-1],height[i]);}
        // int suffix[n];
        // suffix[n-1]=height[n-1];
        // for(int i=n-2;i>=0;i--){
        // suffix[i]=max(suffix[i+1],height[i]);}
        // for(int i=0;i<n;i++){
        //    leftMax= prefix[i];
        //    rightMax=suffix[i];
        //    if(height[i]<leftMax && height[i]<rightMax)
        //     total+=min(leftMax, rightMax) - height[i];
        // }
        // return total;}

        // TC = O(n), SC = O(1)
 
        int l = 0 , r = n-1,total = 0, lmax=0, rmax=0;
        while(l<r){
            if(height[l] <= height[r]){
                if(lmax > height[l]) 
                total+= lmax - height[l];

                else
                lmax=height[l];
                l++;
            }

            else{
                if(rmax > height[r])
                total+=rmax-height[r];
                else 
                rmax = height[r];

                r--;
            }
        }
        return total;
    }
};