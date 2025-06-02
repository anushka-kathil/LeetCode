class Solution {
public:
   vector<int> next(vector<int>& arr, vector<int>& nse){
    int n = arr.size();
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            nse[i] = n;
        }

        else{
           if(arr[i] > arr[st.top()]){
            nse[i] = st.top();
           }
           else {
            while(!st.empty() && arr[i] <= arr[st.top()]){
                st.pop();
            }
            if(!st.empty()) nse[i] = st.top();
            else nse[i] = n;
           }
        }
        st.push(i);
    }
    return nse;
   }

    vector<int> prev(vector<int>& arr, vector<int>& pse){
    int n = arr.size();
    stack<int> st;
    for(int i=0;i<n;i++){
        if(st.empty()){
            pse[i] = -1;
        }

        else{
           if(arr[i] > arr[st.top()]){
            pse[i] = st.top();
           }

           else {
            while(!st.empty() && arr[i] < arr[st.top()]){
                st.pop();
            }
            if(!st.empty()) pse[i] = st.top();
            else pse[i] = -1;
           }
        }
        st.push(i);
    }
    return pse;
   }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
         vector<int> pse(n);
         int mod = 1e9 + 7;
         next(arr,nse);
         prev(arr,pse);
         int sum=0;
         for(int i=0;i<n;i++){
                int right = nse[i] - i;
                int left = i-pse[i];
                sum= (sum + (1LL*left * right * arr[i]) % mod) % mod;
            
         }
        
       return sum;
    }
};