class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge1(nums1.size());
        stack<int> st;
        unordered_map<int, int> mp;
        for(int i=nums2.size()-1;i>=0;i--){
            if(st.empty()){
                mp[nums2[i]] = -1;
            }
            else if(nums2[i] < st.top()) {
               mp[nums2[i]]=st.top();   
            }
            else {
                while(!st.empty() && nums2[i] > st.top()  ){
                    st.pop();
                }
                if(st.empty() == true) mp[nums2[i]] = -1;
                else {
                   mp[nums2[i]] = st.top();
                    }
            }
            st.push(nums2[i]);
        }

        for(int i=0;i<nums1.size();i++){
         nge1[i] = mp[nums1[i]];
        }
        return nge1;
    }
};