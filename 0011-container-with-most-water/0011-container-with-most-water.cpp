class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int ans=0;
        int left=0,right=n-1;
        while(left < right){
            int area= min(height[left],height[right]) * (right-left);
            ans=max(area,ans);

            if(height[left] < height[right])
            left++;
            else
            right--;
        }
       
        return ans;
        
    }
};