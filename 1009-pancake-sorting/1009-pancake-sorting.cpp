class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {

        int n=arr.size();
        bool flag=true;
        vector<int> ans;
        
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
            flag=false;
            break;
            }
        }
        if(flag)
        return ans;

        int maxi=INT_MIN;
        int index=0;

        int ptr=n-1;
        while(ptr>=0){
             maxi=INT_MIN;
            for(int i=0;i<=ptr;i++){
                if(arr[i]>maxi){
                    maxi=arr[i];
                    index=i;
                }
            }
            // cout<<"maxi "<<maxi<<endl;
            //  cout<<"index "<<index<<endl;

             while(index != ptr ){

                // if(maxi == arr[ptr]){
                //     ptr--;
                //     continue;
                // }

                if(index!=0){
                    reverse(arr.begin(),arr.begin()+index+1);
                    ans.push_back(index+1);
                    index=0;
                   

                }

                else if(index == 0 ){
                    reverse(arr.begin(),arr.begin()+ptr+1);
                    ans.push_back(ptr+1);
                     auto it = find(arr.begin(), arr.end(), maxi);
                    index = distance(arr.begin(), it);
                    
                }

                // if(maxi == arr[ptr]){
                //     ptr--;
                //     // continue;
                // }
             }
                ptr--;
            
        }
        return ans;
        
        
        
    }
};