class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        //  if(k==1){
        //     return r-l+1;
        // }
        // int x = pow(r, (double)1 / k);

        // int ans = 0;

        // for(int i = 0; i <= x+1; i++) {

        //     long long val = pow(i, k);

        //     if(val >= l && val <= r) {
        //         ans++;
        //     }
        // }

        // return ans;
        long long left=ceil(pow(l,1.0/k)-1e-9);
        long long right=floor(pow(r,1.0/k)+1e-9);
        
        return (int)(right-left+1);
    }
};