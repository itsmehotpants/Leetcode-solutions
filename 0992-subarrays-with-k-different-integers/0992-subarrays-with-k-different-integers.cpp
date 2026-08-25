class Solution {
public:

int help(vector<int>&nums,int k){
unordered_map<int,int>mp;
int l=0,r=0,ans=0;
while(r<nums.size()){
    mp[nums[r]]++;
    while(mp.size()>k){
        mp[nums[l]]--;
        if(mp[nums[l]]==0) mp.erase(nums[l]);
        l++;
    }
    ans+=r-l+1;
    r++;
}
return ans;  
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return help(nums,k)-help(nums,k-1);
    }
};