class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        string news;

        if(k==num.length()){
            return "0";
        }

        for(int i=0;i<num.length();i++){
        while(!st.empty() && k!=0 && st.top()>(int)num[i]){
            st.pop();
            k--;
         }
        st.push((int)num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        while(!st.empty()){

            news+=st.top();
            st.pop();
        }
        
        while(news.size()!=0 && news.back()=='0'){
            news.pop_back();
        }
        reverse(news.begin(), news.end());
        
        if(news!="")
        return news;
        else
        return "0";
        
    }
};