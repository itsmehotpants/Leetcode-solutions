#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen( int target,vector<int>& nums) {
        // Write your code here
        int n=nums.size();
        int sum  = accumulate(nums.begin(),nums.end(),0);
        if(target>sum) return 0;
       
        int l =0,r=0,len=INT_MAX;
        int subsum=0;
        while(r<n){
            subsum+=nums[r];
            while(subsum>=target){
                len = min(len,r-l+1);
                subsum-=nums[l];
                l++;
            }
            r++;
            
        }
        return len;
    }
};