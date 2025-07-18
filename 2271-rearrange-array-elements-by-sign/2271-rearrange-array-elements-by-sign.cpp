class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        queue<int> qp;
         queue<int> qn;
         vector<int> v;

        for(int i=0; i<n; i++){
            if(i%2==0 && nums[i] > 0 && qp.size()==0 && qn.size()==0|| i%2!=0 && nums[i]<0 && qp.size()==0 && qn.size()==0) { v.push_back(nums[i]);
                continue;
            }

            else if(nums[i] > 0){
                // cout<<"+ "<<nums[i]<<" "<<i<<endl;
                 qp.push(i);

                    if(qn.size() && qp.size()){
                    v.push_back(nums[qp.front()]);
                    v.push_back(nums[qn.front()]);
                    qp.pop();
                    qn.pop();
                }     
            }

            else if(nums[i] < 0){ 
                // cout<<"- "<<nums[i]<<" "<<i<<endl;
                 qn.push(i);
                    if(qn.size() && qp.size()){
                    // swap(nums[qp.front()], nums[qn.front()]);
                    v.push_back(nums[qn.front()]);
                    v.push_back(nums[qp.front()]);
                    qp.pop();
                    qn.pop();
                     }
            }
        }
         return v;     
    }
};