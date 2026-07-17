class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        // string res="";
        // string add="",word="";

        for(char c:s){
            if(c!=']'){
                st.push(c);
            }
            else{
                string str= "";
                while(st.top()!='['){
                    str+=st.top();
                    st.pop();
                }
                reverse(str.begin(),str.end());
                st.pop();

                string num="";
                while(!st.empty() && isdigit(st.top())){
                    num+=st.top();st.pop();
                }
                reverse(num.begin(),num.end());
                int k =stoi(num);

                while(k--){
                    for(char c:str){
                        st.push(c);
                    }
                }

            }
            }
            string ans = "";
            while(!st.empty()){
                ans+=st.top();st.pop();
            }
            reverse(ans.begin(),ans.end());
            return ans;
    }
};