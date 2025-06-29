class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        set<int> s;
        vector<int> v;
        if(n1<=n2){
        for(int i=0; i<n1; i++){
            auto it = std::find(nums2.begin(), nums2.end(), nums1[i]);
            if(it != nums2.end())  s.insert(nums1[i]);

        }
        }
        else{
             for(int i=0; i<n2; i++){
            auto it = std::find(nums1.begin(), nums1.end(), nums2[i]);
            if(it != nums1.end())  s.insert(nums2[i]);

        }

        }
        // v=s;
        // vector<int> v;
        for(auto i:s) v.push_back(i);
        return v;
        
    }
};
