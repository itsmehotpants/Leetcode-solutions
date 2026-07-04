class Solution {
public:
    int minOperations(string s1, string s2) {
        int n= s1.size();
        if(n==1){
            return s1==s2?0:(s1[0]=='0'?1:-1);
        }
        int ans= 0,curr=0;
        for(int i =0;i<n;i++){
            if(s1[i]=='1' && s2[i]=='0'){
                curr++;
            }
            else{
                if(curr>0){
                    ans+=(curr/2)+2*(curr%2);
                    curr=0;
                }
                if(s1[i]=='0' &&s2[i]=='1'){
                    ans++;
                }
            }
        }
        if(curr>0){
                    ans+=(curr/2)+2*(curr%2);
                    curr=0;
                }
        return ans;
    }
};