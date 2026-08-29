class Solution {

    int f(vector<int>& a){
        int n = a.size();
        if(n<2) return 0;
        vector<int> pre(n),suf(n);
        pre[0]=a[0],suf[n-1] = a[n-1];
        for(int i=1;i<n;i++){
            pre[i]=__gcd(pre[i-1],a[i]);
        }
        for(int i =n-2;i>=0;i--){
            suf[i]=__gcd(suf[i+1],a[i]);
        }
        int cnt = 0;
        for(int i = 0;i<n-1;i++){
            if(pre[i]==suf[i+1]) cnt++;
        }
        return cnt;
    }
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int ans =f(nums);

        for(int r= 0;r<n;r++){
            vector<int>temp;
            temp.reserve(n-1);
            for(int i=0;i<n;i++){
                if(i!=r) temp.push_back(nums[i]);
            }
            ans = max(ans,f(temp)); 
        }
        return ans;
    }
};