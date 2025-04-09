class Solution {
public:
   void backTraversing(vector<int>& nums, queue<int>& q) {
        
        stack<int> st;
        int n= nums.size();
                
        for (int i = (2*nums.size()) - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i%n]) {
                st.pop();
            }

            if(i<n){
            if (!st.empty()) {
                q.push(st.top());
            } else {
                q.push(-1);
            }
        }
            st.push(nums[i%n]);
        }
    }



    vector<int> nextGreaterElements(vector<int>& nums) {
    
        queue<int> q;
        vector<int> v(nums.size()); 
        
        
        backTraversing(nums, q);
      
        for (int i = nums.size()-1; i >=0; i--) {
            v[i] = q.front();
            q.pop();  
        }
        
        return v;
    }
};