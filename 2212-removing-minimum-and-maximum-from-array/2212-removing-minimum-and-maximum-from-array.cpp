class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int minIndex=0,maxIndex=0;
        for(int i=0;i<n;i++){
           if(nums[i] < mini) {mini = nums[i]; minIndex = i;}
           if(nums[i] > maxi) {maxi = nums[i]; maxIndex = i;}
        }

        int p1 = max(minIndex-0+1, maxIndex-0+1);
        int p2 = max(n-minIndex , n-maxIndex);
        int p3 = maxIndex-0+1 + n-minIndex;
        int p4 = minIndex-0+1 + n-maxIndex;
        // cout<<p1<<" "<<p2<<" "<<p3<<" "<<p4;

        return min(p1,min(p2,min(p3,p4)));

    }
};