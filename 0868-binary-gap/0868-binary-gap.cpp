class Solution {
public:
    int binaryGap(int n) {
        int ans=0,cur=0;
        bool one =false;
        while(n){
            if(n&1){
                ans = max(ans,cur);
                one =true;
                cur=1;

            }
            else{
                if(one) cur++;
            }
        
        n>>=1;
        }
        return ans;
    }

};