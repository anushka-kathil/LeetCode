class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n=nums.size();
        if(n == 1){
            if(target == nums[0]){
                ans.push_back(0);
                ans.push_back(0);
                return ans;
            }
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
        }

        int start=0;
        int end=nums.size()-1;
        int ind=-1;

        while(start <= end){
            int mid = start + (end-start)/2;

            if(target < nums[mid])
            {
                end=mid-1;
            }
            else if(target > nums[mid]){
                start = mid+1;
            }
            else{
                ind=mid;
                break;
            }
        }

        if(ind == -1){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
       int st_ind=ind;
       int end_ind=ind;
        while(st_ind>0 && nums[st_ind] == nums[st_ind-1]){
            st_ind--;
        }
        while(end_ind < (n-1) && nums[end_ind] == nums[end_ind+1]){
           end_ind++;
        }
        ans.push_back(st_ind);
        ans.push_back(end_ind);
        return ans;

        

        // if(ind < (nums.size()-1)){
        //     if(nums[ind] == nums[ind+1]){
        //     ans.push_back(ind);
        //     ans.push_back(ind+1);
        //     return ans;
        //     }
        //     else if(ind > 0 && nums[ind] == nums[ind-1]){
        //     ans.push_back(ind);
        //     ans.push_back(ind-1);
        //     sort(ans.begin(),ans.end());
        //     return ans;
        //     }
        // }
        
        // ans.push_back(ind);
        // ans.push_back(ind);
        // return ans;

    }
};