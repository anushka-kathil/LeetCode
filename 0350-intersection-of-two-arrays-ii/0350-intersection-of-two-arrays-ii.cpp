class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        map<int,int> m1;
        map<int,int> m2;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        for(int i=0;i<nums1.size();i++){
            m1[nums1[i]]++;
        }

        for(int i=0;i<nums2.size();i++){
            m2[nums2[i]]++;
        }
        
        for(int i=0;i<min(nums1.size(),nums2.size());i++){

            while(nums1.size()<=nums2.size() && m1[nums1[i]] > 0 && m2[nums1[i]] > 0){
                ans.push_back(nums1[i]);
                m1[nums1[i]]--;
                m2[nums1[i]]--;
            }

            while(nums2.size()<nums1.size() && m1[nums2[i]] > 0 && m2[nums2[i]] > 0){
                ans.push_back(nums2[i]);
                m1[nums2[i]]--;
                m2[nums2[i]]--;
            }
        }

        return ans;


    }
};