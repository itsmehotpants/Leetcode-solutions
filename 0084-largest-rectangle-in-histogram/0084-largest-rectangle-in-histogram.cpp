class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n =h.size();
        vector<int>nse(n,n),pse(n,-1);
        stack<int>st,s2;

        for(int i = n-1;i>=0;i--){
            while(!st.empty() && h[i]<=h[st.top()]){
                st.pop();
            }
            if(!st.empty()) nse[i] = st.top();
            st.push(i);
        }

        for(int i = 0;i<n;i++){
            while(!s2.empty() && h[i]<=h[s2.top()]){
                s2.pop();
            }
            if(!s2.empty()) pse[i] = s2.top();
            s2.push(i);
        }
        int area = 0;
        for(int i =0;i<n;i++){
            area = max(area,h[i]*(nse[i]-pse[i]-1));
        }
        return area;
    }
};