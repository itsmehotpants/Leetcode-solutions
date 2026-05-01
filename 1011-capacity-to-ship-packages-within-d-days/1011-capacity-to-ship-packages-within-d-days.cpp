class Solution {
public:

bool help(vector<int>&v,int k,int d){
    int cnt=1,sum=0;
    for(int x:v){
        if(x>k) return false;
        if(sum+x>k){
            cnt++;
            sum=x;
        }
        else sum+=x;
    }
    if(cnt<=d) return true;
    return false;
}
    int shipWithinDays(vector<int>& wt, int d) {
       int l =*max_element(wt.begin(),wt.end());
       int h = 0;
        for(int x : wt){
            h += x;
        }
        int ans=0;
        while(l<=h){
            int mid  =l+(h-l)/2;
            if(help(wt,mid,d)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;

    }
};