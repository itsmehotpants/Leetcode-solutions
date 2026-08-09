class Solution {
public:
    long long numOfSubsequences(string s) {
        long long  n=s.size();
        long long  cntL=0,cntLC=0,cntLCT=0;
        for(char c:s){
            if(c=='L') cntL++;
            else if(c=='C') cntLC+=cntL;
            else if(c=='T') cntLCT+=cntLC;
        }
        vector<long long >prefL(n+1,0),prefLC(n+1,0),sufT(n+1,0),sufCT(n+1,0);
        for(long long  i=0;i<n;i++){
            prefL[i+1]=prefL[i]+(s[i]=='L'?1:0);
            prefLC[i+1] = prefLC[i]+(s[i]=='C'?prefL[i]:0);
        }

         for(long long  i=n-1;i>=0;i--){
            sufT[i]=sufT[i+1]+(s[i]=='T'?1:0);
            sufCT[i] = sufCT[i+1]+(s[i]=='C'?sufT[i+1]:0);
        }

        long long  maxans=0;
        for(long long  i =0;i<=n;i++){
            long long  gainL = sufCT[i];
            long long  gainC = prefL[i]*sufT[i];
            long long  gainT  = prefLC[i];
            maxans = max({maxans,gainL,gainC,gainT });

        }
        return maxans+cntLCT;
        

        
    }
};