class Solution {
public:
    vector<int> twoSum(vector<int>& a, int x) {
        int l =0, r= a.size()-1;
        while(l<r){
            int sum  =a[l]+a[r];
            if(sum==x) return {l+1,r+1};
            else if(sum>x) r--;
            else l++;
        }
        return {};

    }
};