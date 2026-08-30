// class Solution {
//     public:
//     int longestValidParentheses(string s) {
//         int n=s.size();
//         int open =0,close=0;
//         int maxLen =0;

//         for(int i=0;i<s.length();i++){
//             if(s[i]=='('){
//                 open++;
//             }
//             else close++;
            
//                 if(open==close){
//                     int len =open+close;
//                     maxLen=max(maxLen,len);
//                 }
//                 else if(close>open){
//                     open =0,close=0;
//                 }

//             }

//         open =close=0;
//         for(int i =n-1;i>=0;i--){
//             if(s[i]=='(') open++;
//             else close++;
//             if(open==close){
//                 int len =open +close;
//                 maxLen = max(maxLen,len);
//             }
//             else if(open>close) open=close=0;
//         }
//         return maxLen;
//     }
// };


class Solution{
    public:
    int longestValidParentheses(string s){
        int n = s.length();
        stack<int>idx;
        idx.push(-1);
        int mx= 0;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                idx.push(i);
            }
            else{
                idx.pop();
                if(idx.empty()) idx.push(i);
                else mx = max(mx,i-idx.top());
            }
        }
        return mx;
    }
};