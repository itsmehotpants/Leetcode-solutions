class Solution {
public:
    int getLength(vector<int>& nums) {
       int n =nums.size(),res=1;
        for(int i =0;i<n;i++){
            unordered_map<int,int>mp,fcnt;
            int mx=0;
            for(int j=i;j<n;j++){
                int x =nums[j];
                // 0
                if(mp[x]) fcnt[mp[x]]--;
                mp[x]++;
                fcnt[mp[x]]++;
                mx=max(mx,mp[x]);
                if(mp.size()==1){
                    res=max(res,j-i+1);
                    continue;
                }

                if(mx&1) continue;
                
            int half =mx/2;
                bool ok= true,hashalf=false;
                for(auto&[f,c]:fcnt){
                    if(!c) continue;
                    if(f==mx) continue;
                    if(f==half) hashalf=true;
                    else {
                        ok= false;
                        break;
                }}
                
                if(ok && hashalf) res=max(res,j-i+1);
            }
            
        }
        return res;
    }
};