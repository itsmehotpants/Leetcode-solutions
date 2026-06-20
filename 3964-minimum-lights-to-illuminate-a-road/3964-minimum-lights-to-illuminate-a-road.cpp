class Solution {
public:
    int minLights(vector<int>& a) {
        int n =a.size(),ans=0,c=0,len=0;
        vector<int>d(n+1);
        for(int i =0;i<n;i++){
            if(!a[i]) continue;
            d[max(0,i-a[i])]++;
            d[min(n-1,i+a[i])+1]--;
            
        }
        for(int i=0;i<n;i++){
            c+=d[i];
            if(c){
                ans+= (len+2)/3;
                len=0;
            }
            else len++;
        }
        return ans+ (len+2)/3;
    }
};