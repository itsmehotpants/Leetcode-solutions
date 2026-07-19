class Solution {
public:

    int onecnt(string s){
        int cnt1=0;
        for(char c:s){
            if(c=='1') cnt1++;
        }
        return cnt1;
    }
     int qcnt(string s){
        int q=0;
        for(char c:s){
            if(c=='?') q++;
        }
        return q;
    }
    int zerocnt(string s){
        int cnt0=0;
        for(char c:s){
            if(c=='0') cnt0++;
        }
        return cnt0;
    }
    vector<bool> transformStr(string s, vector<string>& strs) {
        int m1  = onecnt(s);
        int m0 = zerocnt(s);
int n =s.size();
        vector<int>s1(n+1,0);
        for(int i =0;i<n;i++){
            s1[i+1] = s1[i]+(s[i]=='1');
        }
        
        
        vector<bool>ans;
       for(auto &t:strs){
           int f=onecnt(t);
           int q  = qcnt(t);
           int z = zerocnt(t);


           int x   =  m1-f;
           if(x<0 ||x>q){
               ans.push_back(false);
               continue;
           }
           int z_need = q-x;
           bool flag =true;
           int q_seen = 0,pref1=0;
           for(int i =0;i<n;i++){
               char c= t[i];
               if(c=='1'){
                   pref1++;
               }
               else if(c=='?'){
                   q_seen++;
                   if(q_seen>z_need) pref1++;
               }
               if(pref1>s1[i+1]){
                   flag =false;
                   break;
               }
           }
           ans.push_back(flag);
       }
return ans;
        
    }
};