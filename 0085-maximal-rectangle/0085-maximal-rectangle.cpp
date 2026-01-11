class Solution {
public:

    int lHist(vector<int>& pSum,int m){
        stack<int> st;
        
        int maxA=0;
        int nse=0,pse=0,element;
        for(int i=0;i<m;i++){
        while(!st.empty() && pSum[st.top()] > pSum[i]){
             element=st.top();
            st.pop();
            nse=i;
            pse=st.empty()?-1:st.top();
          maxA=max(maxA, pSum[element]*(nse-pse-1));
        }
        st.push(i);
        }

        while(!st.empty()){
            nse=m;
            element=st.top();
            st.pop();
            pse=st.empty()?-1:st.top();
            maxA=max(maxA, pSum[element]*(nse-pse-1));
        }
        return maxA;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        cout<<n<<" "<<m;
        // int pSum[n][m];
        vector<vector<int>> pSum(n, vector<int>(m, 0));
        int sum=0;
        // prefix sum

        for(int j=0;j<=m-1;j++){
            sum=0;
            for(int i=0;i<=n-1;i++){
                
                if(matrix[i][j]=='0')
                sum=0;
                else
                sum+=1;

                pSum[i][j]=sum; 

            }
        }
        // cout<<"***";
        int maxArea=0;
        for(int i=0;i<n;i++){
            maxArea=max(maxArea, lHist(pSum[i],m));
        }
        // cout<<"%%%";
        return maxArea;


        
    }
};