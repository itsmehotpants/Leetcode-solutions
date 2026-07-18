class Solution {
public:
    int trap(vector<int>& h) {
        int n =h.size(),l=0,r=n-1,lmax=0,rmax=0,ans=0;
        while(l<r){
            if(h[l]<h[r]){
                if(h[l]>lmax) lmax=h[l];
                else ans  += lmax-h[l];
                l++;
            }
            else{
                if(h[r]>rmax) rmax= h[r];
                else ans +=rmax-h[r];
                r--;
            }
        }
        return ans;
    }
};