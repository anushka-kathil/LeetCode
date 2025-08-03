class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans;
        vector<int> copy = arr;
        sort(copy.begin(),copy.end());
        copy.erase(unique(copy.begin(), copy.end()), copy.end());
        unordered_map<int,int> m;
        for(int i=0; i<arr.size();i++){
           if(m.find(copy[i]) == m.end()) 
           m[copy[i]]=i+1;
        }
        for(int i=0; i<arr.size();i++){
            ans.push_back(m[arr[i]]);
        }
        return ans;
    }
};