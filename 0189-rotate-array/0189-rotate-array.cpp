class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        deque<int> q;
        int n = nums.size();
        for(int i:nums){
            q.push_back(i);
        }
        while(k--){
            int e = q.back();
            q.pop_back();
            q.push_front(e);
        }
        nums.clear();
        for(int i:q){
            nums.push_back(i);
        }
    }
};